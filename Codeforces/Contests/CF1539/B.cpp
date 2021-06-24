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
const int A = 26;

int n, q;
string s;
int dp[A][N];

int main()
{
  cin >> n >> q;
  cin >> s;
  for(int i = 0; i < A; i++) {
    for(int j = 0; j < n; j++) {
      dp[i][j] = (s[j] - 'a') == i;
      if(j > 0) dp[i][j] += dp[i][j - 1];
    }
  }
  for(int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r; --l, --r;
    int ans = 0;
    for(int j = 0; j < A; j++) {
      int cnt = dp[j][r] - (l > 0 ? dp[j][l - 1] : 0);
      ans += cnt * (j + 1);
    }
    cout << ans << endl;
  }
  return 0;
}
