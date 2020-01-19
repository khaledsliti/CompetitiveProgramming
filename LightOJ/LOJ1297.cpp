#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

double area(double a, double b, double x)
{
  return (a - 2 * x) * (b - 2 * x) * x;
}

double solve(double w, double l)
{
  double a = 12;
  double b = -4 * (w + l);
  double c = w * l;
  double delta = b * b - 4.0 * a * c;
  double x1 = (-b -sqrt(delta)) / (2.0 * a);
  return area(w, l, x1);
}

double solve1(double a, double b)
{
  double l = 0, r = min(a, b) / 2.0;
  while(fabs(r - l) > 1e-7){
    double x1 = (2.0 * l + r) / 3.0;
    double x2 = (l + 2.0 * r) / 3.0;
    double f1 = area(a, b, x1);
    double f2 = area(a, b, x2);
    if(f1 > f2) r = x2;
    else if(f1 < f2) l = x1;
    else l = x1, r = x2;
  }
  return area(a, b, l);
}

int main()
{
  int T, tc = 1;
  scanf("%d", &T);
  while(T--){
    double a, b;
    scanf("%lf%lf", &a, &b);
    printf("Case %d: %.9f\n", tc++, solve1(a, b));
  }
  return 0;
}
