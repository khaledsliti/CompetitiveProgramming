// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
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
#define colliner pointOnLine

bool pointOnLine(const point& a, const point& b, const point& p)
{
    // degenerate case: line is a point
    return fabs(cross(vec(a,b),vec(a,p))) < EPS;
}

const int N = 200001;

struct obs {
  int t, x, a, idx;
};

int n, h;
obs arr[N];
int ans[N];

void solve() {
  scanf("%d%d", &h, &n);
  for(int i = 0 ; i < n; i++) {
    int t, x, a;
    scanf("%d%d%d", &t, &x, &a);
    arr[i] = {t, x, a, i};
  }
  sort(arr, arr + n, [](const obs& u, const obs& v) {
    return u.x < v.x;
  });
  for(int i = 0 ; i < n ; i++)
    ans[i] = 0;
  for(int i = 0 ; i < n ; i++) {
    int lo = 0, hi = h, x_lo = arr[i].x + 1, x_hi = arr[i].x + 1;
    for(int j = i + 1 ; j < n ; j++) {
      if(arr[i].x == arr[j].x) {
        ans[arr[i].idx]++;
        ans[arr[j].idx]++;
      } else {
        bool b1 = 1LL * (lo - arr[i].a) * (arr[j].x - arr[i].x) < 1LL * (arr[j].a - arr[i].a) * (x_lo - arr[i].x);
        bool b2 = 1LL * (hi - arr[i].a) * (arr[j].x - arr[i].x) > 1LL * (arr[j].a - arr[i].a) * (x_hi - arr[i].x);
        if(b1 && b2) {
          ++ans[arr[i].idx];
          ++ans[arr[j].idx];
        }
        if(arr[j].t == 0 && b1) x_lo = arr[j].x, lo = arr[j].a;
        else if(arr[j].t == 1 && b2) x_hi = arr[j].x, hi = arr[j].a;
      }
    }
  }
  for(int i = 0 ; i < n ; i++)
    printf("%d%c", ans[i], " \n"[i == n - 1]);
}

int main()
{
  int T;
  scanf("%d", &T);
  while(T--) {
    solve();
  }
  return 0;
}
