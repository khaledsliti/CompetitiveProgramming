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

const int N = 25;

int n;
int arr[2][N];
long long dp[N][2];

long long solve(int i, int last) {
  if(i >= n) return 0;
  long long& r = dp[i][last];
  if(r != -1) return r;
  long long a = abs(arr[last][i - 1] - arr[0][i]) + abs(arr[1 - last][i - 1] - arr[1][i]) + solve(i + 1, 0);
  long long b = abs(arr[last][i - 1] - arr[1][i]) + abs(arr[1 - last][i - 1] - arr[0][i]) + solve(i + 1, 1);
  r = min(a, b);
  return r;
}

void solve() {
  cin >> n;
  for(int j = 0; j < 2; j++) {
    for(int i = 0; i < n; i++) {
      cin >> arr[j][i];
    }
  }
  memset(dp, -1, sizeof dp);
  cout << min(solve(1, 0), solve(1, 1)) << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int T;
  cin >> T;
  while(T--) {
    solve();
  }
  return 0;
}
