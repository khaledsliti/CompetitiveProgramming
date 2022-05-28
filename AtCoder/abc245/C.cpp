// RedStone
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;

const int N = 2e5 + 5;

int n, k;
int a[2][N];
int dp[N][2];

int solve(int i, int last) {
  if(i >= n) return 1;
  int& r = dp[i][last];
  if(r != -1) return r;
  r = 0;
  for(int x = 0; x < 2; x++) {
    if((i == 0 || abs(a[last][i - 1] - a[x][i]) <= k) && solve(i + 1, x)) {
      r = 1;
      break;
    }
  }
  return r;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> k;
  for(int i = 0; i < n; i++) {
    cin >> a[0][i];
  }  
  for(int i = 0; i < n; i++) {
    cin >> a[1][i];
  }
  memset(dp, -1, sizeof dp);
  cout << (solve(0, 0) ? "Yes" : "No") << endl;
  return 0;
}
