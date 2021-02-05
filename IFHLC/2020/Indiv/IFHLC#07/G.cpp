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

const int N = 207;

int n;
point p[N];
ll val[N];
ll dp[N][N][N];

int db_cmp(double a, double b) {
  if(fabs(a - b) < EPS) return 0;
  return (a > b) * 2 - 1;
}

double triangleArea3points(const point& a, const point& b, const point& c) {
  if(a == b || a == c || b == c) return 0;
  return fabs(cross(a, b) + cross(b, c) + cross(c, a)) / 2;
}

long long area2(const point& a, const point& b, const point& c) {
  return 2 * triangleArea3points(a, b, c);
}

ll solve(int i, int j, int cur) {
  if(cur >= n) return 0;
  ll& r = dp[i][j][cur];
  if(r != -1) return r;
  r = solve(i, j, cur + 1) + val[cur];
  r = max(r, area2(p[i], p[j], p[cur]) + solve(i, cur, cur + 1));
  return r;
}

int main()
{
  cin >> n;
  ll best = 0;
  for(int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y >> val[i];
    p[i] = point(x, y);
    best += val[i];
  }

  memset(dp, -1, sizeof dp);
  
  ll acc = 0;
  for(int i = 0; i < n; i++) {
    best = max(best, acc + solve(i, i, i + 1));
    acc += val[i];
  }

  cout << best << endl;

  return 0;
}
