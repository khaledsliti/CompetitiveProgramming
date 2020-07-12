// We only fail when we stop trying
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
int dp[N];

void dfs(int u) {
  dp[u] = 0;
  for(int v: g[u]) {
    dfs(v);
    dp[u] += 1 + dp[v];
  }
}

int main()
{
  cin >> n;
  for(int i = 1; i < n; i++) {
    int p; cin >> p;
    g[--p].push_back(i);
  }
  dfs(0);
  for(int i = 0; i < n; i++)
    cout << dp[i] << " ";
  cout << endl;
  return 0;
}
