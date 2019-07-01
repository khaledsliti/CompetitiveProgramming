/********************************************************************************************************
  Author: RedStone

  Problem link:
    https://www.facebook.com/hackercup/problem/862237970786911/

  Idea:
    We build a graph using the given edges. Calculate all possible shortest paths using Floyd-Warshall and check if the given input is optimized or not.

  Compexity:
    Time: O(N ^ 3)
    Memory: O(N ^ 2)
********************************************************************************************************/
#include <bits/stdc++.h>
using namespace std;

const int N = 51;
const int oo = 1e9;

int n, m;
int g[N][N];

int main()
{
  int T, tc(1);
  cin >> T;
  while (T--) {
    cin >> n >> m;
    for(int i = 0 ; i < n ; i++)
      for(int j = 0 ; j < n ; j++)
        g[i][j] = i == j ? 0 : oo;
    vector<pair<pair<int, int>, int>> sol;
    while(m--) {
      int a, b, c;
      cin >> a >> b >> c;
      sol.push_back({{a, b}, c});
      --a, --b;
      g[a][b] = g[b][a] = c;
    }
    for(int k = 0 ; k < n ; k++) {
      for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < n ; j++)
          g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
      }
    }
    bool good = true;
    for(auto& edge : sol) {
      int u = edge.first.first - 1;
      int v = edge.first.second - 1;
      int c = edge.second;
      if(g[u][v] < c){
        good = false;
        break;
      }
    }
    cout << "Case #" << tc++ << ": ";
    if(good) {
      cout << sol.size() << endl;
      for(auto& edge : sol)
        cout << edge.first.first << " " << edge.first.second << " " << edge.second << endl;
    }else{
      cout << "Impossible" << endl;
    }
  }
  return 0;
}
