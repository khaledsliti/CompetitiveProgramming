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

int n, cur_index;
int col[N], val[N];
vector<int> g[N];
vector<pair<int, int>> queries[N];
int bit[N];
int ans[N];

void add(int idx, int val) {
  for(int i = idx + 1; i < N; i += i & -i)
    bit[i] += val;
}

int get(int idx) {
  int res = 0;
  for(int i = idx + 1; i > 0; i -= i & -i)
    res += bit[i];
  return res;
}

void dfs(int u, int p) {
  val[cur_index] = col[u];
  int left = cur_index++;
  for(int v: g[u])
    if(v != p) {
      dfs(v, u);
    }
  queries[cur_index - 1].push_back({left, u});
}

int main()
{
  cin >> n;
  for(int i = 0; i < n; i++)
    cin >> col[i];
  for(int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    g[a].pb(b);
    g[b].pb(a);
  }
  dfs(0, -1);
  map<int, int> last;
  for(int i = 0; i < n; i++) {
    if(last.count(val[i]))
      add(last[val[i]], -1);
    add(i, 1);
    last[val[i]] = i;
    for(auto q: queries[i]) {
      int l = q.first;
      int idx = q.second;
      ans[idx] = get(i) - get(l - 1);
    }
  }
  for(int i = 0; i < n; i++)
    cout << ans[i] << " ";
  cout << endl;
  return 0;
}
