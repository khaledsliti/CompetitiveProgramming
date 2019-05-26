#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
typedef long long ll;
const int mod = 1e9 + 7;
const int N = 1e5 + 6;

int n;
double p[N];

int main()
{
  cin >> n;
  double ans = 0.0;
  double soFar = 0;
  for(int i = 0 ; i < n ; i++){
    cin >> p[i];
    soFar = soFar * p[i] + p[i] * p[i - 1];
    ans += 2.0 * soFar + p[i];
  }
  cout << fixed << setprecision(18) << ans << endl;
  return 0;
}