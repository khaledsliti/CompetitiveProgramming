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

const int N = 5e5 + 5;

int n, q;
int nxt[N];
int par[N];

int find(int x) {
  return par[x] == x ? x : par[x] = find(par[x]);
}

int getNxt(int x) {
  return nxt[x] == x ? x : nxt[x] = getNxt(nxt[x]);
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> q;
  iota(par, par + n, 0);
  iota(nxt, nxt + n, 0);

  while(q--) {
    int t, x, y;
    cin >> t >> x >> y;
    --x, --y;
    if(t == 1) {
      int rx = getNxt(x);
      int ry = getNxt(y);
      x = find(rx), y = find(ry);
      par[x] = y;
    } else if(t == 2) {
      for(int cur = getNxt(x); ; cur = getNxt(++cur)) {
        par[find(cur)] = find(getNxt(y));
        if(cur == getNxt(y)) break;
        nxt[cur] = getNxt(y);
      }
    } else {
      cout << (find(getNxt(x)) == find(getNxt(y)) ? "YES" : "NO") << endl;
    }
  }
  return 0;
}
