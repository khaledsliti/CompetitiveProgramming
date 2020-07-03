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
int to[N], in[N], out[N];
set<int> g[N];

vector<int> find_path(int src) {
  stack<int> cur_path;
  cur_path.push(src);
  vector<int> path;
  int cur_node = 0;
  while(!cur_path.empty()) {
    if(!g[cur_node].empty()) {
      cur_path.push(cur_node);
      int nxt = *g[cur_node].begin();
      int nxt_node = to[nxt];
      g[cur_node].erase(nxt);
      cur_node = nxt_node;
    } else {
      path.push_back(cur_node);
      cur_node = cur_path.top();
      cur_path.pop();
    }
  }
  reverse(all(path));
  return path;
}

int main()
{
  cin >> n >> m;
  for(int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    out[a]++;
    in[b]++;
    g[a].insert(i);
    to[i] = b;
  }
  for(int i = 1; i < n - 1; i++)
    if(in[i] != out[i]) {
      cout << "IMPOSSIBLE" << endl;
      return 0;
    }
  if(out[0] != in[0] + 1 || out[n - 1] + 1 != in[n - 1]) {
    cout << "IMPOSSIBLE" << endl;
    return 0;
  }
  auto sol = find_path(0);
  if(sz(sol) != m + 1) {
    cout << "IMPOSSIBLE" << endl;
    return 0;
  }
  for(int node: sol)
    cout << node + 1 << " ";
  cout << endl;
  return 0;
}
