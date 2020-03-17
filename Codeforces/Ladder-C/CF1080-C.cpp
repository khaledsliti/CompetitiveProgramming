// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

int n, m;
int x1, x2, y1, y2;
int x3, x4, y3, y4;
int w, b;

pair<long long, long long> calc(int l, int r, int d, int u) {
  long long x = r - l + 1;
  long long y = u - d + 1;
  long long w = ((x + 1) / 2) * ((y + 1) / 2) + (x / 2) * (y / 2);
  long long b = x * y - w;
  if((l + d) & 1) return {b, w};
  return {w, b};
}

long long area(int x1, int x2, int y1, int y2) {
  return 1LL * (x2 - x1 + 1) * (y2 - y1 + 1);
}

void solve() {
  scanf("%d%d", &n, &m);
  scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
  scanf("%d%d%d%d", &x3, &y3, &x4, &y4);
  pair<long long, long long> res = calc(1, n, 1, m);
  auto tmp = calc(x1, x2, y1, y2);
  res.first -= tmp.first;
  res.second -= tmp.second;
  tmp = calc(x3, x4, y3, y4);
  res.first -= tmp.first;
  res.second -= tmp.second;
  int xl = max(x1, x3);
  int xr = min(x2, x4);
  int yl = max(y1, y3);
  int yr = min(y2, y4);
  if(xl <= xr && yl <= yr) {
    tmp = calc(xl, xr, yl, yr);
    res.first += tmp.first;
    res.second += tmp.second;
    res.first += area(x1, x2, y1, y2) - area(xl, xr, yl, yr);
    res.second += area(x3, x4, y3, y4);
  } else {
    res.first += area(x1, x2, y1, y2);
    res.second += area(x3, x4, y3, y4);
  }
  cout << res.first << " " << res.second << endl;
}


int main()
{
  int t;
  scanf("%d", &t);
  while(t--) {
    solve();
  }
  return 0;
}
