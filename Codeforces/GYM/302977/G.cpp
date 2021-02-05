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

int v1, v2;
int t, d;
int dp[100][10005];

int solve(int i, int v) {
  if(i >= t) {
    return v == v2 ? 0 : -1e9;
  }
  int& r = dp[i][v];
  if(r != -1) return r;
  r = -1e9;
  for(int dv = max(1, v - d); dv <= v + d; dv++) {
    r = max(r, dv + solve(i + 1, dv));
  }
  return r;
}

int main()
{
  cin >> v1 >> v2 >> t >> d;
  memset(dp, -1, sizeof dp);
  cout << v1 + solve(1, v1) << endl;
  return 0;
}
