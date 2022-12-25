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

const int N = 5005;

int n, m;
int x[N];
int y[N];
long long dp[N][N];

long long solve(int i, int cnt) {
  if(i >= n) return 0;
  long long& r = dp[i][cnt];
  if(r != -1) return r;
  r = x[i] + y[cnt + 1] + solve(i + 1, cnt + 1);
  r = max(r, solve(i + 1, 0));
  return r;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    cin >> x[i];
  }
  for(int i = 0; i < m; i++) {
    int c;
    cin >> c;
    cin >> y[c];
  }
  memset(dp, -1, sizeof dp);
  cout << solve(0, 0) << endl;
  return 0;
}
