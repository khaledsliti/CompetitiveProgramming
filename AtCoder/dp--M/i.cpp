// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 3010;

int n;
double p[N];
double dp[N];

int main()
{
  cin >> n;
  for(int i = 0 ; i < n ; i++)
    cin >> p[i];
  dp[0] = 1;
  for(int i = 1 ; i <= n ; i++) {
    for(int j = i ; j >= 0 ; j--) {
      dp[j] = dp[j] * (1 - p[i - 1]) + dp[j - 1] * p[i - 1];
    }
  }
  double sum = 0;
  for(int i = n / 2 + 1; i <= n ; i++)
    sum += dp[i];
  cout << fixed << setprecision(10) << sum << endl;
  return 0;
}
