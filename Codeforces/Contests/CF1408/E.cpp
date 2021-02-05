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

int n, m;
int a[N], b[N];
vector<array<int, 3>> edge;
int par[N];

int fs(int x) {
  return x == par[x] ? x : par[x] = fs(par[x]);
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> m >> n;
  for(int i = 0; i < m; i++) {
    cin >> a[i];
  }
  for(int i = 0; i < n; i++) {
    cin >> b[i];
  }
  ll ans = 0;
  for(int i = 0; i < m; i++) {
    int k;
    cin >> k;
    while(k--) {
      int x;
      cin >> x;
      --x;
      ans += a[i] + b[x];
      edge.push_back({a[i] + b[x], n + i, x});
    }
  }
  n += m;
  for(int i = 0; i < n; i++) {
    par[i] = i;
  }
  sort(all(edge));
  reverse(all(edge));
  for(int i = 0; i < sz(edge); i++) {
    int c = edge[i][0], u = edge[i][1], v = edge[i][2];
    u = fs(u), v = fs(v);
    if(u != v) {
      ans -= c;
      par[v] = u;
    }
  }

  cout << ans << endl;
  return 0;
}
