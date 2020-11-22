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

double dp[N][N][N];
int vis[N][N][N];

double p(double t, double n) {
  return t / n;
}

double solve(int a, int b, int c) {
  if(max(max(a, b), c) >= 100) {
    return 0.0;
  }
  double& r = dp[a][b][c];
  if(vis[a][b][c]) {
    return r;
  }
  vis[a][b][c] = 1;
  r = 0.0;
  r += p(a, a + b + c) * (1 + solve(a + 1, b, c));
  r += p(b, a + b + c) * (1 + solve(a, b + 1, c));
  r += p(c, a + b + c) * (1 + solve(a, b, c + 1));
  return r; 
}

int main()
{
  int a, b, c;
  cin >> a >> b >> c;
  memset(vis, 0, sizeof vis);

  cout << fixed << setprecision(10) << solve(a, b, c) << endl;
  return 0;
}
