#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) begin(x), end(x)
typedef complex<double> point;
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

const int N = 105;

int n;
double d, r;
point pts[N];

void solve(point center, int& best)
{
  int ans = 0;
  for(int i = 0 ; i < n ; i++)
    if(length(vec(center, pts[i])) <= r)
      ans++;
  best = max(best, ans);
}

int main()
{
  int tests;
  cin >> tests;
  while(tests--){
    cin >> n >> d;
    r = d / 2.0;
    for(int i = 0 ; i < n ; i++){
      double x, y;
      cin >> x >> y;
      pts[i] = point(x, y);
    }
    int best = 0;
    bool good = false;
    for(int i = 0 ; i < n ; i++){
      for(int j = i + 1 ; j < n ; j++){
        if(pts[i] == pts[j])
          continue;
        good = true;
        point ab = vec(pts[i], pts[j]);
        double dis = length(ab);
        double alpha = acos(dis / d);
        solve(pts[i] + r * rotate(normalize(ab), alpha), best);
        solve(pts[i] + r * rotate(normalize(ab), -alpha), best);
      }
    }
    if(!good)
      best = max(best, n);
    cout << best << endl;
  }
  return 0;
}
