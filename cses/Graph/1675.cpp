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
int par[N];
vector<array<int,3>> edges;

int fs(int x) {
  return par[x] == x ? x : par[x] = fs(par[x]);
}

int main()
{
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    par[i] = i;
  }
  while(m--) {
    int a, b, c;
    cin >> a >> b >> c;
    edges.pb({c, a, b});
  }
  sort(all(edges));
  ll ans = 0, g = n;
  for(int i = 0; i < sz(edges); i++) {
    int a = edges[i][1], b = edges[i][2];
    int c = edges[i][0];
    a = fs(a), b = fs(b);
    if(a != b) {
      ans += c;
      par[a] = b;
      g--;
    }
  }
  if(g != 1) cout << "IMPOSSIBLE" << endl;
  else cout << ans << endl;
  return 0;
}
