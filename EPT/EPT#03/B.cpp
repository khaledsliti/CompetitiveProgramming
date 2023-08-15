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

const int N = 1e5 + 5;

int n;
int arr[2][N];
ll dp[N][2];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < n; j++) {
      cin >> arr[i][j];
    }
  }

  for (int i = n - 1; i >= 0; i--) {
    dp[i][0] = max(dp[i + 1][0], dp[i + 1][1] + arr[0][i]);
    dp[i][1] = max(dp[i + 1][1], dp[i + 1][0] + arr[1][i]);
  }
  cout << max(dp[0][0], dp[0][1]) << endl;
  return 0;
}
