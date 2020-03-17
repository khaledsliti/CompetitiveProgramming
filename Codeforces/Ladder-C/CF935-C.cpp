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
#define X real()
#define Y imag()
#define vec(a,b) ((b)-(a))
#define length(v) ((double)hypot((v).Y,(v).X))
#define normalize(p) ((p)/length(p))

void print(point A, double r) {
  cout << fixed << setprecision(10) << A.X << " " << A.Y << " " << r << endl;
}

int main()
{
  double R, x1, y1, x2, y2;
  cin >> R >> x1 >> y1 >> x2 >> y2;
  point C(x1, y1);
  point A(x2, y2);
  if(A == C) {
    print(point(x1 + R / 2, y1), R / 2);
    return 0;
  }
  point AC = vec(A, C);
  if(length(AC) >= R) {
    print(C, R);
    return 0;
  }
  double r = (length(AC) + R) / 2;
  point B = r * normalize(AC) + A;
  print(B, r);
  return 0;
}
