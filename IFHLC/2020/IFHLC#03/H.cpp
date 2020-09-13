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

const int N = 105;

int n;
int a[N];
int lis[N][N];
int dp[N];

void solve() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for(int i = 0; i < n; i++) {
    for(int j = i; j < n; j++) {
      lis[i][j] = 1;
      for(int k = i; k < j; k++) {
        if(a[k] < a[j]) {
          lis[i][j] = max(lis[i][j], 1 + lis[i][k]);
        }
      }
    }
    for(int j = i + 1; j < n; j++) {
      lis[i][j] = max(lis[i][j], lis[i][j - 1]);
    }
  }
  for(int k = 1; k <= n; k++) {
    dp[n] = 0;
    for(int i = n - 1; i >= 0; i--) {
      dp[i] = 0;
      for(int j = i; j < n; j++) {
        if(lis[i][j] >= k) {
          dp[i] = max(dp[i], lis[i][j] + dp[j + 1]);
        }
      }
    }
    cout << dp[0] << " ";
  }
  cout << endl;
}

int main()
{
  int T;
  cin >> T;
  while(T--) {
    solve();
  }
  return 0;
}
