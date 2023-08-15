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

const int N = 52;

int n;
int arr[N];
int can[N][N][N];
int dp[N][N][N];
vector<long long> s;

int solve(int i, int j, int k) {
  if (k >= n) {
    return 0;
  }
  int& r = dp[i][j][k];
  if (r != -1) {
    return r;
  }
  r = solve(i, j, k + 1);
  if (can[i][j][k]) {
    r = max(r, 1 + solve(j, k, k + 1));
  }
  return r;
}

void Solve() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      for (int k = j + 1; k < n; k++) {
        int d1 = arr[j] - arr[i];
        int d2 = arr[k] - arr[j];
        int d3 = arr[k] - arr[i];
        can[i][j][k] = 3 < d1 && d1 < d2;
      }
    }
  }
  for (int i = 0; i < n ;i++) {
    for (int j = 0; j < n; j++) {
      for (int k = j + 1; k < n ;k++) {
        cout << i << " " << j << " " << k << " " << can[i][j][k] << endl;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        dp[i][j][k] = -1;
      }
    }
  }
  int ans = 1;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if ((arr[j] - arr[i]) % 2 == 0) {
        continue;
      }
      ans = max(ans, 2 + solve(i, j, j + 1));
    }
  }
  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int T;
  cin >> T;
  while (T--) {
    Solve();
  }
  return 0;
}
