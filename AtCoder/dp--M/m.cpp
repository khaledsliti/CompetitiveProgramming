// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
typedef long long ll;

const int N = 105;
const int V = 1e5 + 5;
const int Mod = 1e9 + 7;

int n, k;
int a[N];
int dp[V];
int acc[V];

int main()
{
  cin >> n >> k;
  for(int i = 0 ; i < n ; i++) {
    cin >> a[i];
  }
  for(int j = 0; j <= k; j++)
    acc[j] = 1;
  for(int i = 0 ; i < n ; i++) {
    for(int j = 0 ; j <= k; j++) {
      dp[j] = acc[j];
      if(j - a[i] - 1 >= 0)
        dp[j] = ((dp[j] - acc[j - a[i] - 1]) % Mod + Mod) % Mod;
    }
    acc[0] = dp[0];
    for(int j = 1 ; j <= k ; j++)
      acc[j] = (acc[j - 1] + dp[j]) % Mod;
  }
  cout << dp[k] << endl;
  return 0;
}
