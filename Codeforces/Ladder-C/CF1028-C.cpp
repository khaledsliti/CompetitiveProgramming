// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

struct seg {
  int l, r;
  seg() : l(0), r(0) {}
  seg(int l, int r) : l(l), r(r) {}
  bool empty() {
    return l > r;
  }
};

struct rec {
  seg x, y;
  rec(){}
  rec(seg x, seg y) : x(x), y(y) {}
  bool empty() {
    return x.empty() || y.empty();
  }
};

seg Intersect(seg a, seg b) {
  return { max(a.l, b.l), min(a.r, b.r) };
}

rec Intersect(rec a, rec b) {
  return { Intersect(a.x, b.x), Intersect(a.y, b.y) };
}

const int N = 2e5 + 5;
const int oo = 1e9 + 1;

int n;
rec big = {{-oo, oo}, {-oo, oo}};
rec arr[N];
rec L[N], R[N];

bool check(int idx, int& x, int& y) {
  rec inter = big;
  if(idx > 0)
    inter = Intersect(inter, L[idx - 1]);
  if(idx + 1 < n)
    inter = Intersect(inter, R[idx + 1]);
  if(!inter.empty()){
    x = inter.x.l;
    y = inter.y.l;
    return true;
  }
  return false;
}

int main()
{
  scanf("%d", &n);
  for(int i = 0 ; i < n ; i++) {
    int x1, x2, y1, y2;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    arr[i] = { {x1, x2}, {y1, y2} };
  }
  L[0] = arr[0];
  R[n - 1] = arr[n - 1];
  for(int i = 1, j = n - 2; i < n ; i++, j--) {
    L[i] = Intersect(L[i - 1], arr[i]);
    R[j] = Intersect(R[j + 1], arr[j]);
  }
  int x, y;
  for(int i = 0 ; i < n ; i++) {
    if(check(i, x, y))
      return cout << x << " " << y << endl, 0;
  }
  return 0;
}
