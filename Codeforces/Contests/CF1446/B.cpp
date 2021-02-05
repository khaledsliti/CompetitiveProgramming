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

const int N = 5007;

int n, m;
string A, B;
int vis[N][N];
int dp[N][N];

int solve(int i, int j) {
  if(i >= n || j >= m) return 0;
  int& r = dp[i][j];
  if(vis[i][j]) return r;
  vis[i][j] = 1;
  r = 0;
  r = max(r, solve(i + 1, j) - 1);
  r = max(r, solve(i, j + 1) - 1);
  if(A[i] == B[j]) {
    r = max(r, 2 + solve(i + 1, j + 1));
  }
  return r;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m;
  cin >> A >> B;
  memset(vis, 0, sizeof vis);
  int ans = 0;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      ans = max(ans, solve(i, j));
    }
  }
  cout << ans << endl;
  return 0; 
}
