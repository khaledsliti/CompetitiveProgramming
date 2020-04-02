// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define double long double

#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define EPS 1e-9
#define OO 1e9
#define X real()
#define Y imag()
#define vec(a,b) ((b)-(a))
#define polar(r,t) ((r)*exp(point(0,(t))))
#define angle(v) (atan2((v).Y,(v).X))
#define length(v) ((double)hypot((v).Y,(v).X))
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
typedef complex<double> point;

enum STATE
{
    IN, OUT, BOUNDRY
};

//get angle opposite to side a
double cosRule(double a, double b, double c)
{
    // Handle denom = 0
    double res = (b * b + c * c - a * a) / (2 * b * c);
    if (fabs(res-1)<EPS)
        res = 1;
    if (fabs(res+1)<EPS)
        res = -1;
    return acos(res);
}

int circleCircleIntersection(const point &c1, const double &r1,
                             const point &c2, const double &r2,
                             point &res1, point &res2)
{
  if (same(c1, c2) && fabs(r1 - r2) < EPS)
  {
    res1 = res2 = c1;
    return fabs(r1) < EPS ? 1 : OO;
  }
  double len = length(vec(c1, c2));
  if (fabs(len - (r1 + r2)) < EPS || fabs(fabs(r1 - r2) - len) < EPS)
  {
    point d, c;
    double r;
    if (r1 > r2)
      d = vec(c1, c2), c = c1, r = r1;
    else
      d = vec(c2, c1), c = c2, r = r2;
    res1 = res2 = normalize(d) * r + c;
    return 1;
  }
  if (len > r1 + r2 || len < fabs(r1 - r2))
    return 0;
  double a = cosRule(r2, r1, len);
  point c1c2 = normalize(vec(c1, c2)) * r1;
  res1 = rotate(c1c2, a) + c1;
  res2 = rotate(c1c2, -a) + c1;
  return 2;
}

// point % cercle
STATE circlePoint(const point & cen, const double & r, const point& p)
{
  double lensqr = lengthSqr(vec(cen,p));
  if (fabs(lensqr - r * r) < EPS)
    return BOUNDRY;
  if (lensqr < r * r)
    return IN;
  return OUT;
}

bool inside(const point& c1, const double& r1, const point& c2, const double r2)
{
  if(circlePoint(c2, r2, c1) == OUT)
    return false;
    
}

const int N = 61;

int n, k;
point p[N];
int c[N];
double r[N];

bool check(double t)
{
  for (int i = 0; i < n; i++)
    r[i] = t / c[i];
  for(int i = 0 ; i < n ; i++) {
    int inside = 0;
    for(int j = 0 ; j < n ; j++) {
      inside += circlePoint(p[i], r[i], p[j]) != OUT;
    }
    if(inside >= k)
      return true;
    for(int j = i + 1 ; j < n ; j++) {
      point A, B;
      int cnt = circleCircleIntersection(p[i], r[i], p[j], r[j], A, B);
      vector<point> pts;
      if(cnt > 0) pts.pb(A);
      if(cnt > 1) pts.pb(B);
      for(point v : pts) {
        int dis = 0;
        for(int d = 0 ; d < n ; d++) {
          dis += circlePoint(p[d], r[d], v) != OUT;
        }
        if(dis >= k)
          return true;
      }
    }
  }
  return false;
}

int main()
{
  cin >> n >> k;
  for (int i = 0; i < n; i++){
    int x, y;
    cin >> x >> y >> c[i];
    p[i] = point(x, y);
  }
  if (k == 1) {
    cout << 0 << endl;
    return 0;
  }
  double l = 0, r = 1e6;
  for(int i = 0 ; i < 100 ; i++) {
    double mid = l + (r - l) / 2;
    if (check(mid))
      r = mid;
    else
      l = mid;
  }
  cout << fixed << setprecision(10) << l << endl;
  return 0;
}
