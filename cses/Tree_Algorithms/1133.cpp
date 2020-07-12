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

int n;
int sub[N], lev[N];
vector<int> g[N];
ll dp[N];

void calc(int u, int p) {
  sub[u] = 1;
  for(int v: g[u])
    if(v != p) {
      lev[v] = 1 + lev[u];
      dp[0] += lev[v];
      calc(v, u);
      sub[u] += sub[v];
    }
}

void dfs(int u, int p) {
  for(int v: g[u])
    if(v != p) {
      dp[v] = dp[u] + n - 2 * sub[v];
      dfs(v, u);
    }
}

int main()
{
  cin >> n;
  for(int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    g[a].push_back(b);
    swap(a, b);
    g[a].push_back(b);
  }
  lev[0] = dp[0] = 0;
  calc(0, -1);
  dfs(0, -1);
  for(int i = 0; i < n; i++)
    cout << dp[i] << " ";
  cout << endl;
  return 0;
}
