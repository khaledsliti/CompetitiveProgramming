// RedStone
#include <bits/stdc++.h>
using namespace std;
typedef complex<long double> point;
#define sz(a) ((int)(a).size())
#define all(n) (n).begin(),(n).end()
#define EPS 1e-9
#define OO 1e9
#define X real()
#define Y imag()
#define vec(a,b) ((b)-(a))
#define polar(r,t) ((r)*exp(point(0,(t))))
#define angle(v) (atan2((v).Y,(v).X))
exit
v) ((long double)hypot((v).Y,(v).X))
#define lengthSqr(v) (dot(v,v))
#define dot(a,b) ((conj(a)*(b)).real())
#define cross(a,b) ((conj(a)*(b)).imag())
#define rotate(v,t) (polar(v,t))
#define rotateabout(v,t,a)  (rotate(vec(a,v),t)+(a))
#define reflect(p,m) ((conj((p)/(m)))*(m))
#define normalize(p) ((p)/length(p))
#define same(a,b) (lengthSqr(vec(a,b))<EPS)
#define mid(a,b) (((a)+(b))/point(2,0))
#define perp(a) (point(-(a).Y,(a).X))


long double x, y, r;

int db_cmp(long double a, long double b) {
  if (fabs(a - b) < EPS)
    return 0;
  return (a > b) * 2 - 1;
}

bool isInside(point a) {
  return db_cmp(length(vec(a, point(x, y))), r) <= 0;
}

int calc(point a) {
  int lo = 0, hi = 3 * floor(r), right = 0;
  while(lo <= hi) {
    int mid = (lo + hi) / 2;
    if(isInside(point(a.X + mid, a.Y))) {
      right = mid;
      lo = mid + 1;
    } else {
      hi = mid - 1;
    }
  }
  lo = 0, hi = 3 * floor(r);
  int left = 0;
  while(lo <= hi) {
    int mid = (lo + hi) / 2;
    if(isInside(point(a.X - mid, a.Y))) {
      left = mid;
      lo = mid + 1;
    } else {
      hi = mid - 1;
    }
  }
  return right + left + 1;
}

void solve(point a) {
  long long ans = 0;
  for(int i = -3e5; i <= 3e5; i++) {
    point b = {a.X, a.Y + i};
    if(isInside(b)) {
      ans += calc(b);
    }
  }
  cout << ans << endl;
  exit(0);
}

int main()
{
  cin >> x >> y >> r;
  point a = {round(x), round(y)};
  if(isInside(a)) {
    solve(a);
  } else {
    cout << 0 << endl;
  }
  return 0;
}
