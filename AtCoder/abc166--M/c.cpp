// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 1e5 + 5;

int n, m;
int h[N];
vector<int> g[N];

int main()
{
  cin >> n >> m;
  for(int i = 0 ; i < n ; i++)
    cin >> h[i];
  for(int i = 0 ; i < m ; i++) {
    int a, b;
    cin >> a >> b;
    g[--a].pb(--b);
    g[b].pb(a);
  }
  int ans = 0;
  for(int i = 0 ; i < n ; i++) {
    int mx = 0;
    for(int v : g[i])
      mx = max(mx, h[v]);
    ans += mx <  h[i];
  }
  cout << ans << endl;
  return 0;
}
