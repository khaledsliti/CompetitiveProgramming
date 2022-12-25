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

const int N = 1e7 + 7;

int n, m;
int dp[100][100];
// int dp[100][100][4];

// int solve(int rem, int cur, int last) {
//   if(rem == 0) {
//     return 1;
//   }
//   if(cur > m) {
//     return 0;
//   }
//   int& r = dp[rem][cur][last + 1];
//   if(r != -1) {
//     return r;
//   }
//   r = solve(rem, cur + 1, last);
//   if(cur % 3 != last) {
//     r += solve(rem - 1, cur + 1, cur % 3);
//   }
//   return r;
// }

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m;

  // memset(dp, -1, sizeof dp);
  // for(int i = 1; i <= n; i++) {
  //   for(int j = 0; j <= m; j++) {
  //     cout << solve(i, j, -1) << "\t";
  //   }
  //   cout << endl;
  // }
  

  for(int j = 1; j <= m; j++) {
    dp[1][j] = 1;
  }

  for(int i = 2; i <= n; i++) {
    for(int j = 1; j + i - 1 <= m; j++) {

    }
  }

  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      cout << dp[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
