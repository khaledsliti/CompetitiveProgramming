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

const int N = 18;
const int INF = 1e9;

int n;
int x[N], y[N], z[N];
int dist[N][N];
int dp[N][1 << N];

int solve(int cur, int mask) {
  if(mask == (1 << n) - 1) {
    return dist[cur][0];
  }
  int& r = dp[cur][mask];
  if(r != -1) return r;
  r = INF;
  for(int nxt = 0; nxt < n; nxt++) {
    if(!(mask & (1 << nxt))) {
      r = min(r, dist[cur][nxt] + solve(nxt, mask | (1 << nxt)));
    }
  }
  return r;
}

int main()
{
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> x[i] >> y[i] >> z[i];
  }
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      dist[i][j] = abs(x[i] - x[j]) + abs(y[i] - y[j]) + max(0, z[j] - z[i]);
    }
  }
  memset(dp, -1, sizeof dp);
  cout << solve(0, 1) << endl;
  return 0;
}
