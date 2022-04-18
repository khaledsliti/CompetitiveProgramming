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

const int N = 1e6;

int n;
int dp[N];

int main()
{
  dp[0] = 0;
  for(int i = 32768 - 1; i > 0; i--) {
    dp[i] = 1 + dp[i + 1];
    int x = i, c = 0;
    while(x % 2 == 0) x /= 2, c++;
    x = i / x;
    dp[i] = min(dp[i], 15 - c);
  }

  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    cout << dp[n] << " ";
  }
  cout << endl;
  return 0;
}
