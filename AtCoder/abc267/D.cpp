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

const int N = 2005;
const long long Inf = 1e18;

int n, m;
int arr[N];
int vis[N][N];
long long dp[N][N];

long long solve(int i, int cnt) {
  if(cnt > m) {
    return 0;
  }
  if(i >= n) {
    return -Inf;
  }
  if(vis[i][cnt]) {
    return dp[i][cnt];
  }
  vis[i][cnt] = 1;
  return dp[i][cnt] = max(solve(i + 1, cnt),
    1LL * cnt * arr[i] + solve(i + 1, cnt + 1));
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  cout << solve(0, 1) << endl;
  return 0;
}
