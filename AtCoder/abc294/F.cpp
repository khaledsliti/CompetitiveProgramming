// RedStone
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

const int N = 5e4 + 5;

int n, m;
long long k;
double a[N], b[N], c[N], d[N];

long long count(double x) {
  vector<double> f(m);
  for (int i = 0; i < m; i++) {
    f[i] = c[i] - x / 100.0 * d[i];
  }
  sort(all(f));

  long long ret = 0;
  for (int i = 0; i < n; i++) {
    double target = (x * b[i] - 100.0 * a[i]) / 100.0;
    ret += upper_bound(all(f), target) - begin(f);
  }
  return ret;
}

/*
A / B
C / D

100 * (A + C) / (B + D) <= x
100 * (A + C) <= x (B + D)


100 A + 100 C <= x B + x D
100 C <= x B + x D - 100 A
C <= (x B - 100 A) / 100 + x/100 D

C - x/100 D <= (x B - 100 A) / 100

*/

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m >> k;
  k = 1LL * n * m - k + 1;
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
    b[i] += a[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> c[i] >> d[i];
    d[i] += c[i];
  }

  // for (int i = 0; i < n; i++) {
  //   for(int j = 0; j < m; j++) {
  //     cout << i << " " << j << " " << (a[i] + c[j]) / (b[i] + d[j]) << endl;
  //   }
  // }

  double low = 0.0, high = 100.0;
  for (int i = 0; i < 100; i++) {
    double mid = (low + high) / 2.0;
    // cout << low << " " <<  mid << " -> " << count(mid) << endl;
    if (count(mid) >= k) {
      high = mid;
    } else {
      low = mid;
    }
  }

  cout << fixed << setprecision(12) << (low + high) / 2.0 << endl;
  return 0;
}
