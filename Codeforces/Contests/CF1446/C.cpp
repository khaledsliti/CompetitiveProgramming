// RedStone
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
const int Log = 30;

int n;
int a[N];
int L[N], R[N];
int par[N], siz[N];

int fs(int x) {
  return par[x] == x ? x : par[x] = fs(par[x]);
}

void us(int x, int y) {
  x = fs(x), y = fs(y);
  if(x != y) {
    par[x] = y;
    siz[y] += siz[x];
  }
}

int calc(int x, int b) {
  while(b >= 0 && !(x & (1 << b))) {
    b--;
  }
  return b + 1;
}

int calc(int l, int r, int b) {
  if(b < 0) return 0;
  vector<pair<int, int>> seg;
  for(int i = l; i <= r; i++) {
    seg.push_back({i, 0});
    int j = i;
    while(j <= r && calc(a[j], b) == calc(a[i], b)) {
      j++;
      seg.back().second++;
    }
    i = j - 1;
  }
  int best = n;
  int before = 0, after = 0, nb_after = 0;
  int st = l;
  for(int i = 0; i < sz(seg); i++) {
    after += seg[i].second;
    nb_after++;
  }
  for(int i = 0; i < sz(seg); i++) {
    int en = st + seg[i].second - 1;
    after -= seg[i].second;
    nb_after--;
    best = min(best, max(0, before - 1) + calc(st, en, b - 1) + after - nb_after);
    st += seg[i].second;
    before += seg[i].second;
  }
  return best;
}

int main()
{
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  sort(a, a + n);
  cout << calc(0, n - 1, Log - 1) << endl;
  return 0;
}
