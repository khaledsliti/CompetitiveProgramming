/********************************************************************************************************
  Author: RedStone

  Idea:
    We build the directed graph in which the nodes are the cells and between any neighboring cells we add an edges.
    We merge all strongly connected component nodes to build a new dag. The cost of the component is the sum of all costs of its nodes.
    Finally we can get the answer by finding the maximum possible sum of a path starting from the component of cell (0, 0).

  Complexity:
    Time: O(N * M)
    Memory: O(N * M)
********************************************************************************************************/
#include <bits/stdc++.h>
using namespace std;

#define DEB(x) cout << #x << " = " << x << endl;

class MarbleCollectionGame{
  int n;
  vector<int> cost;
  vector<vector<int>> g;

  int dfsIndex, nbrComp;
  vector<int> idx, low;
  vector<int> compOf, costComp;
  stack<int> st;

  vector<vector<int>> dag;
  vector<int> dp;

  void addEdge(int u, int v){
    g[u].push_back(v);
  }

  void build_graph(vector <string>& board){
    int r = board.size();
    int c = board[0].size();
    n = r * c;
    g.clear(); g.resize(n);
    cost.clear(); cost.resize(n, 0);
    auto getIndex = [&](int i, int j){ return i * c + j; };
    for(int i = 0 ; i < r ; i++){
      for(int j = 0 ; j < c ; j++){
        char cur = board[i][j];
        if(cur == '#')
          continue;
        cost[getIndex(i, j)] = (cur >= '0' && cur <= '9') ? (cur - '0') : 0;
        if(j + 1 < c) addEdge(getIndex(i, j), getIndex(i, j + 1));
        if(i + 1 < r) addEdge(getIndex(i, j), getIndex(i + 1, j));
        if(cur == 'L' && j > 0 && board[i][j - 1] != '#') addEdge(getIndex(i, j), getIndex(i, j - 1));
        if(cur == 'U' && i > 0 && board[i - 1][j] != '#') addEdge(getIndex(i, j), getIndex(i - 1, j));
      }
    }
  }

  void dfs(int cur){
    idx[cur] = low[cur] = dfsIndex++;
    st.push(cur);
    for(int i = 0 ; i < (int) g[cur].size() ; i++){
      int nxt = g[cur][i];
      if(idx[nxt] == -1){
        dfs(nxt);
        low[cur] = min(low[cur], low[nxt]);
      }else if(compOf[nxt] == -1){
        low[cur] = min(low[cur], low[nxt]);
      }
    }
    if(low[cur] == idx[cur]){
      costComp.push_back(0);
      while(true){
        int t = st.top();
        st.pop();
        compOf[t] = nbrComp;
        costComp.back() += cost[t];
        if(t == cur)
          break;
      }
      nbrComp++;
    }
  }

  void stronglyConnected(){
    dfsIndex = nbrComp = 0;
    idx.clear(); idx.resize(n, -1);
    low.clear(); low.resize(n);
    compOf.clear(); compOf.resize(n, -1);
    costComp.clear();
    for(int i = 0 ; i < n ; i++)
      if(idx[i] == -1)
        dfs(i);
  }

  void build_dag(){
    dag.clear();
    dag.resize(nbrComp);
    for(int i = 0 ; i < n ; i++){
      for(int j = 0 ; j < (int) g[i].size() ; j++){
        int u = compOf[i], v = compOf[g[i][j]];
        if(u != v)
          dag[u].push_back(v);
      }
    }
  }

  int longuest_path_on_dag(int cur){
    int& r = dp[cur];
    if(r != -1)
      return r;
    r = 0;
    for(int i = 0 ; i < (int) dag[cur].size() ; i++){
      int nxt = dag[cur][i];
      r = max(r, longuest_path_on_dag(nxt));
    }
    return r = r + costComp[cur];
  }

  void print_graph(vector<vector<int>>& graph){
    cout << graph.size() << endl;
    for(int i = 0 ; i < (int)graph.size() ; i++){
      cout << i << ":";
      for(int j = 0 ; j < (int)graph[i].size() ; j++)
        cout << " " << graph[i][j];
      cout << endl;
    }
  }
public:
  int collectMarble(vector <string> board){
    build_graph(board);
    stronglyConnected();
    build_dag();
    // print_graph(dag);
    dp.clear(); dp.resize(n, -1);
    return longuest_path_on_dag(compOf[0]);
  }
};

int main()
{
  MarbleCollectionGame sol = MarbleCollectionGame();
  cout << sol.collectMarble({"264", "3LL"}) << endl;
  cout << sol.collectMarble({"8U4L9", "0183U", "U8#38", "2158#", "L65U7"}) << endl;
  cout << sol.collectMarble({"039LLLU", "953348#", "0L87#29", "718#4#U", "594U196"}) << endl;
  return 0;
}
