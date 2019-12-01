#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 1e5 + 5;
const int mod = 1e9 + 7;

int n;
vector<pair<int, pair<int, int>>> edges;
int par[N];
int siz[N];

int fs(int u)
{
  return u == par[u] ? u : par[u] = fs(par[u]);
}

int main()
{
  cin >> n;
  for(int i = 0 ; i < n ; i++){
    par[i] = i;
    siz[i] = 1;
  }
  for(int i = 1 ; i < n ; i++){
    int a, b, c;
    cin >> a >> b >> c;
    edges.pb({c, {--a, --b}});
  }
  sort(all(edges));
  int ans = 0;
  for(int i = 0 ; i < sz(edges) ; i++){
    int c = edges[i].first;
    int a = edges[i].second.first;
    int b = edges[i].second.second;
    a = fs(a);
    b = fs(b);
    int cur = (((1LL * siz[a] * siz[b]) % mod) * c) % mod;
    ans = (ans + cur) % mod;
    par[a] = b;
    siz[b] += siz[a];
  }
  cout << ans << endl;
  return 0;
}
