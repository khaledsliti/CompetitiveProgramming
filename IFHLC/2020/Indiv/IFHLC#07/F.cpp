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

typedef complex<double> point;
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

int db_cmp(double a, double b) {
  if(fabs(a - b) < EPS) return 0;
  return (a > b) * 2 - 1;
}

point center, a;
double s, ri, rf, sa;

void print(double x) {
  cout << fixed << setprecision(10) << x << endl;
}

int main()
{
  double x, y;
  cin >> x >> y;
  center = point(x, y);
  cin >> s >> ri >> rf;
  cin >> x >> y;
  a = point(x, y);
  cin >> sa;

  double dist = length(vec(center, a));

  if(db_cmp(dist, ri) > 0) {
    if(db_cmp(sa, s) <= 0) {
      print((dist - rf) / sa);
    } else {
      double t = (dist - ri) / (sa - s);
      double d = min(dist - rf, t * sa);
      print(d / sa);
    }
  } else {
    if(db_cmp(sa, s) >= 0) {
      print(0);
    } else {
      double t = (ri - dist) / (s - sa);
      double d = t * sa;
      if(db_cmp(dist - d, rf) >= 0) {
        double rem = dist - d - rf;
        print(rem / sa);
      } else {
        print(0);
      }
    }
  }
  
  return 0;
}
