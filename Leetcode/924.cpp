#include <bits/stdc++.h>
using namespace std;

class Solution {
  short fs(vector<short>& p, short x)
  {
    return p[x] == x ? x : p[x] = fs(p, p[x]);
  }

public:
  int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
    int n = graph.size();

    vector<short> infected(n, 0);
    for(auto& x : initial)
      infected[x] = 1;
    vector<short> par(n), sz(n, 1), minInf(n);

    for(short i = 0 ; i < n ; i++){
      par[i] = i;
      minInf[i] = infected[i] ? i : n;
    }
    
    for(short i = 0 ; i < n ; i++){
      for(short j = i + 1 ; j < n ; j++){
        if(i != j && graph[i][j]){
          short u = fs(par, i);
          short v = fs(par, j);
          if(u != v){
            par[u] = v;
            sz[v] += sz[u];
            infected[v] += infected[u];
            minInf[v] = min(minInf[v], minInf[u]);
          }
        }
      }
    }

    short biggest = 0, best;
    for(short i = 0 ; i < n ; i++){
      if(fs(par, i) == i){
        if(infected[i] == 1 && (biggest < sz[i] || (biggest == sz[i] && best > minInf[i]))){
          biggest = sz[i];
          best = minInf[i];
        }
      }
    }
    if(biggest > 0)
      return best;
    return *min_element(initial.begin(), initial.end());
  }
};

int main()
{
  Solution sol = Solution();
  vector<vector<int>> graph = {{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 1}, {0, 0, 1, 1}};
  vector<int> initial = {3, 1};
  cout << sol.minMalwareSpread(graph, initial) << endl;
  return 0;
}