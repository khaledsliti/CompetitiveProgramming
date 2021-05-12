// Guess Who's Back
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

const int N = 1e5 + 5;
const int V = 200;
const int Mod = 998244353;

int n;
int arr[N];
int dp[N][V + 1][2];
int pref_dp[N][V + 1][2];

int main()
{
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", arr + i);
  }

  for(int j = 1; j <= V; j++) {
    dp[0][j][0] = arr[0] == -1 ? 1 : (arr[0] == j);
    pref_dp[0][j][0] = (pref_dp[0][j - 1][0] + dp[0][j][0]) % Mod;
  }

  for(int i = 1; i < n; i++) {
    for(int j = 1; j <= V; j++) {
      if(arr[i] == -1 || arr[i] == j) {
        dp[i][j][0] = (pref_dp[i - 1][j - 1][0] +  pref_dp[i - 1][j - 1][1]) % Mod;
        dp[i][j][1] = (dp[i - 1][j][0] + (pref_dp[i - 1][V][1] - pref_dp[i - 1][j - 1][1]) % Mod) % Mod;
      }
    }
    for(int j = 1; j <= V; j++) {
      pref_dp[i][j][0] = (pref_dp[i][j - 1][0] + dp[i][j][0]) % Mod;
      pref_dp[i][j][1] = (pref_dp[i][j - 1][1] + dp[i][j][1]) % Mod;
    }
  }

  printf("%d\n", (pref_dp[n - 1][V][1] + Mod) % Mod);
  return 0;
}
