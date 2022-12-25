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

const int N = 101;

int n;
int vis[N];
double dp[N];

double solve(int turns) {
  if(turns > n) {
    return 0;
  }
  if(vis[turns]) {
    return dp[turns];
  }
  vis[turns] = 1;
  dp[turns] = 0;

  for(int cur = 1; cur <= 6; cur++) {
    dp[turns] += 1 / 6.0 * max(1.0 * cur, solve(turns + 1));
  }

  return dp[turns];
}

int main()
{
  cin >> n;
  cout << fixed << setprecision(10) << solve(1) << endl;
  return 0;
}
