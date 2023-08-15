#include <bits/stdc++.h>
using namespace std;

typedef complex<double> point;
#define sz(a) ((int)(a).size())
#define all(n) (n).begin(), (n).end()
#define EPS 1e-12
#define OO 1e9
#define X real()
#define Y imag()
#define vec(a, b) ((b) - (a))
#define polar(r, t) ((r)*exp(point(0, (t))))
#define angle(v) (atan2((v).Y, (v).X))
#define length(v) ((double)hypot((v).Y, (v).X))
#define lengthSqr(v) (dot(v, v))
#define dot(a, b) ((conj(a) * (b)).real())
#define cross(a, b) ((conj(a) * (b)).imag())
#define rotate(v, t) (polar(v, t))
#define rotateabout(v, t, a) (rotate(vec(a, v), t) + (a))
#define reflect(p, m) ((conj((p) / (m))) * (m))
#define normalize(p) ((p) / length(p))
#define same(a, b) (lengthSqr(vec(a, b)) < EPS)
#define mid(a, b) (((a) + (b)) / point(2, 0))
#define perp(a) (point(-(a).Y, (a).X))
#define colliner pointOnLine

enum STATE { IN, OUT, BOUNDRY };

bool intersect(const point& a, const point& b, const point& p, const point& q,
               point& ret) {
  // handle degenerate cases (2 parallel lines, 2 identical lines,   line is 1
  // point)
  double d1 = cross(p - a, b - a);
  double d2 = cross(q - a, b - a);
  ret = (d1 * q - d2 * p) / (d1 - d2);
  if (fabs(d1 - d2) > EPS) return 1;
  return 0;
}

bool pointOnLine(const point& a, const point& b, const point& p) {
  // degenerate case: line is a point
  return fabs(cross(vec(a, b), vec(a, p))) < EPS;
}

bool pointOnRay(const point& a, const point& b, const point& p) {
  // IMP NOTE: a,b,p must be collinear
  // chech if it's in the same direction as the [a,b)
  return dot(vec(a, p), vec(a, b)) > -EPS;
}

bool pointOnSegment(const point& a, const point& b, const point& p) {
  if (same(a, b)) return same(a, p);
  if (!colliner(a, b, p)) return 0;
  return pointOnRay(a, b, p) && pointOnRay(b, a, p);
}

STATE pointInPolygon(const vector<point>& p, const point& pnt) {
  point p2 = pnt + point(1, 0);
  int cnt = 0;
  for (int i = 0; i < sz(p); i++) {
    int j = (i + 1) % sz(p);
    if (same(p[i], p[j])) continue;
    if (pointOnSegment(p[i], p[j], pnt)) return BOUNDRY;
    point r;
    if (!intersect(pnt, p2, p[i], p[j], r)) continue;
    if (!pointOnRay(pnt, p2, r)) continue;
    if (same(r, p[i]) || same(r, p[j]))
      if (fabs(r.Y - min(p[i].Y, p[j].Y)) < EPS) continue;
    if (!pointOnSegment(p[i], p[j], r)) continue;
    cnt++;
  }
  return cnt & 1 ? IN : OUT;
}

void solve() {
  int n, m;
  cin >> n >> m;
  vector<point> polygon;
  for (int i = 0; i < n; i++) {
    double x, y;
    cin >> x >> y;
    polygon.push_back({x, y});
  }
  int ans = 0;
  for (int i = 0; i < m; i++) {
    double x, y;
    cin >> x >> y;
    STATE st = pointInPolygon(polygon, {x, y});
    ans += st == IN || st == BOUNDRY;
  }
  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int T;
  cin >> T;
  while(T--) {
    solve();
  }

  return 0;
}