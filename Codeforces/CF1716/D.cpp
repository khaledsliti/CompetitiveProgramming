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

const int Mod = 998244353;
const int N = 2e5 + 5;
const int S = 448;

int n, k;
int dp[2][N];
int ok[N], tmp[N];
int ans[N];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> k;
  int cur = 0, prv = 1;
  dp[cur][0] = 1;
  ok[0] = 1;
  int sum = 0;
  for(int j = k; j <= n; j++) {
    sum += j;
    if(sum > n) break;
    swap(cur, prv);
    for(int i = 0; i <= n; i++) {
      dp[cur][i] = 0;
    }
    for(int i = 0; i <= n; i++) {
      if(i - j < 0) continue;
      if(ok[i - j]) {
        dp[cur][i] = (dp[cur][i] + dp[prv][i - j]) % Mod;
        tmp[i] = 1;
      }
      if(tmp[i - j]) {
        dp[cur][i] = (dp[cur][i] + dp[cur][i - j]) % Mod;
        tmp[i] = 1;
      }
      ans[i] = (ans[i] + dp[cur][i]) % Mod;
    }
    for(int i = 0; i <= n; i++) {
      ok[i] = tmp[i];
      tmp[i] = 0;
    }
  }
  for(int i = 1; i <= n; i++) {
    cout << ans[i] << " ";
  }
  cout << endl;
  return 0;
}
