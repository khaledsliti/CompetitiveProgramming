// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
typedef long long ll;

const int N = 2e5 + 5;

int n, m;
int to[N], deg[N];
set<int> g[N];

int main()
{
  cin >> n >> m;
  for(int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    g[--a].insert(i);
    g[--b].insert(i);
    to[i] = a ^ b;
    deg[a]++, deg[b]++;
  }
  for(int i = 0; i < n; i++) {
    if(deg[i] & 1) {
      cout << "IMPOSSIBLE" << endl;
      return 0;
    }
  }
  stack<int> cur_path;
  cur_path.push(0);
  vector<int> cycle;
  int cur_node = 0;
  while(!cur_path.empty()) {
    if(deg[cur_node] > 0) {
      cur_path.push(cur_node);
      int nxt = *g[cur_node].begin();
      int nxt_node = to[nxt] ^ cur_node;
      g[cur_node].erase(nxt);
      g[nxt_node].erase(nxt);
      deg[cur_node]--;
      deg[nxt_node]--;
      cur_node = nxt_node;
    } else {
      cycle.push_back(cur_node);
      cur_node = cur_path.top();
      cur_path.pop();
    }
  }
  if(sz(cycle) != m + 1) {
    cout << "IMPOSSIBLE" << endl;
    return 0;
  }
  for(int i : cycle)
    cout << i + 1 << " ";
  cout << endl;
  return 0;
}
