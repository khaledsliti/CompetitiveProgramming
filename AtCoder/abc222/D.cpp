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

const int N = 3007;
const int Mod = 998244353;

int n;
int a[N], b[N];
int dp[N][N];

int solve(int i, int last) {
  if(i >= n) {
    return 1;
  }
  int& r = dp[i][last];
  if(r != -1) {
    return r;
  }
  r = 0;
  if(last >= a[i] && last <= b[i]) {
    r = solve(i + 1, last);
  }
  if(last >= a[i] && last + 1 <= b[i]) {
    r = (r + solve(i, last + 1)) % Mod;
  }
  if(last < a[i]) {
    r = solve(i, a[i]);
  }
  return r;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for(int i = 0; i < n; i++) {
    cin >> b[i];
  }
  memset(dp, -1, sizeof dp);
  cout << solve(0, a[0]) << endl;
  return 0;
}
