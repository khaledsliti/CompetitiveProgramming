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



int main()
{
  int n;
  cin >> n;
  int a[n];
  int mx = INT_MIN;
  double s2 = 0;
  ll c = 0;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    mx = max(mx, abs(a[i]));
    s2 += 1LL * a[i] * a[i];
    c += abs(a[i]);
  }
  s2 = sqrt(s2);

  cout << c << endl;
  cout << fixed << setprecision(10) << s2 << endl;
  cout << mx << endl;
  return 0;
}
