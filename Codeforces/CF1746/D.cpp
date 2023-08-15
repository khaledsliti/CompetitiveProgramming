#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;

const int N = 2e5 + 5;

int n;
vector<int> g[N];
int s[N];

map<int, long long> dp[N];

long long dfs(int u, int k) {
  if (dp[u].count(k)) {
    return dp[u][k];
  }
  long long ret = 1LL * s[u] * k;

  int ch = sz(g[u]);
  if(!ch) {
    return dp[u][k] = ret;
  }

  vector<long long> diff;
  for(int v: g[u]) {
    ret += dfs(v, k / ch);
    diff.push_back(dfs(v, k / ch + 1) - dfs(v, k / ch));
  }
  int cnt = k % ch;
  if(cnt == 0) {
    return dp[u][k] = ret;
  }
  sort(rall(diff));
  for(int i = 0; i < cnt; i++) {
    ret += diff[i];
  }

  return dp[u][k] = ret;
}

void solve() {
  int k;
  cin >> n >> k;
  for(int i = 0; i < n; i++) {
    g[i].clear();
  }
  for(int i = 1; i < n; i++) {
    int p; cin >> p; --p;
    g[p].push_back(i);
  }
  for(int i = 0; i < n; i++) {
    cin >> s[i];
  }
  for(int i = 0; i < n; i++) {
    dp[i].clear();
  }
  cout << dfs(0, k) << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int T;
  cin >> T;
  while(T--) {
    solve();
  }
  return 0;
}
