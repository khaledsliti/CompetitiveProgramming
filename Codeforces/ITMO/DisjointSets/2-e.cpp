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
vector<array<int, 3>> e;
int par[N];

int fs(int x) {
  return x == par[x] ? x : par[x] = fs(par[x]);
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m;
  for(int i = 0; i < m; i++) {
    int x, y, c;
    cin >> x >> y >> c;
    e.push_back({c, --x, --y});
  }
  sort(all(e));
  ll ans = 0;
  iota(par, par + n, 0);
  for(int i = 0; i < m; i++) {
    int a = e[i][1], b = e[i][2], c = e[i][0];
    a = fs(a);
    b = fs(b);
    if(a != b) {
      par[a] = b;
      ans += c;
    }
  }
  cout << ans << endl;
  return 0;
}
