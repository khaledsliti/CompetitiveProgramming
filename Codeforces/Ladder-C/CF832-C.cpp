// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

#define double long double

const int N = 100'010;
const int Max = 1'000'000;

struct item {
  int d, v;
};

int n, s;
vector<item> lf, rt;
int acc[2][Max];

bool check(double t) {
  for(int i = 0 ; i < Max ; i++)
    acc[0][i] = acc[1][i] = 0;
  for(int i = 0 ; i < sz(lf) ; i++) {
    double d = lf[i].d;
    double vi = lf[i].v;
    if(d <= t * vi) {
      acc[0][1]++;
    } else {
      double r = (t * (s + vi) - d) * (s - vi) / s;
      int other = lround(min((double)Max, floor(lf[i].d + r)));
      acc[0][lf[i].d]++;
      if(other + 1 < Max)
        acc[0][other + 1]--;
    }
  }
  for(int i = 0 ; i < sz(rt) ; i++) {
    double d = rt[i].d;
    double vi = rt[i].v;
    if(d <= t * vi) {
      acc[1][1]++;
    } else {
      double r = (t * (s + vi) - d) * (s - vi) / s;
      int other = lround(max((double)0.0, ceil(Max - rt[i].d - r)));
      acc[1][other]++;
      if(rt[i].d + 1 < Max)
        acc[1][rt[i].d + 1]--;
    }
  }

  for(int i = 1 ; i < Max ; i++)
    for(int j = 0 ; j < 2 ; j++)
      acc[j][i] += acc[j][i - 1];
  for(int i = 1 ; i < Max ; i++) {
    if(acc[0][i] > 0 && acc[1][i] > 0)
      return true;
  }
  return false;
}

int main()
{
  scanf("%d%d", &n, &s);
  for(int i = 0 ; i < n ; i++) {
    int x, v, t;
    scanf("%d%d%d", &x, &v, &t);
    if(t == 1) lf.pb({x, v});
    else rt.pb({Max - x, v});
  }

  double l = 0, r = 1e6;
  for(int it = 0; it < 100; it++) {
    double t = (l + r) / 2.0;
    if(check(t)) r = t;
    else l = t;
  }
  cout << fixed << setprecision(15) << (r + l) / 2 << endl;
  return 0;
}
