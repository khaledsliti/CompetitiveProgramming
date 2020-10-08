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
const int V = 1e6 + 5;
const int L = 19;

int n, q;
struct Movie {
  int l, r;
  Movie() {}
  Movie(int _l, int _r): l(_l), r(_r) {}
  bool operator<(const Movie& other) {
    if(l != other.l) return l < other.l;
    return r < other.r;
  }
} mv[N];
int mn[N];
int nxt[N][L];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> q;
  for(int i = 0; i < n; i++) {
    cin >> mv[i].l >> mv[i].r;
  }

  sort(mv, mv + n);
  for(int i = n - 1; i >= 0; i--) {
    mn[i] = i;
    if(i + 1 < n && mv[i].r > mv[mn[i + 1]].r) {
      mn[i] = mn[i + 1];
    }
  }

  for(int i = 0; i < n; i++) {
    int idx = lower_bound(mv, mv + n, Movie(mv[i].r, mv[i].r)) - mv;
    nxt[i][0] = idx < n ? mn[idx] : -1;
  }

  for(int j = 1; j < L; j++) {
    for(int i = 0; i < n; i++) {
      if(nxt[i][j - 1] != -1) {
        nxt[i][j] = nxt[nxt[i][j - 1]][j - 1];
      } else {
        nxt[i][j] = -1;
      }
    }
  }

  while(q--) {
    int a, b;
    cin >> a >> b;
    int idx = lower_bound(mv, mv + n, Movie(a, a)) - mv;
    int st = mn[idx];
    if(st == -1 || mv[st].r > b) {
      cout << 0 << endl;
    } else {
      int cur = st, ans = 1;
      for(int j = L - 1; j >= 0; j--) {
        if(nxt[cur][j] != -1 && mv[nxt[cur][j]].r <= b) {
          cur = nxt[cur][j];
          ans += (1 << j);
        }
      }
      cout << ans << endl;
    }
  }

  return 0;
}
