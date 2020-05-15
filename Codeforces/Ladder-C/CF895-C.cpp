// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
 
const int N = 100010;
const int Mod = 1e9 + 7;

int dp[71][1 << 19];
int pr[19] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67};
int msk[71];
int ways[71][2];
 
int solve(int cur, int acc) {
  if(cur > 70)
    return acc == 0;
  int& r = dp[cur][acc];
  if(r != -1) return r;
  r = 0;
  r = (r + 1LL * ways[cur][0] * solve(cur + 1, acc) % Mod) % Mod;
  r = (r + 1LL * ways[cur][1] * solve(cur + 1, acc ^ msk[cur]) % Mod) % Mod;
  return r;
}
 
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  for(int i = 1 ; i <= 70; i++) {
    int v = i;
    for(int j = 0 ; j < 19 ; j++) {
      int cnt = 0;
      while(v % pr[j] == 0)
        v /= pr[j], cnt++;
      if(cnt & 1)
        msk[i] |= (1 << j);
    }
  }
  for(int i = 0 ; i <= 70; i++)
    ways[i][0] = 1;
  int n;
  cin >> n;
  for(int i = 0 ; i < n ; i++) {
    int a; cin >> a;
    ways[a][0] = ways[a][1] = (ways[a][0] + ways[a][1]) % Mod;
  }
  memset(dp, -1, sizeof dp);
  cout << (solve(1, 0) + Mod - 1) % Mod << endl;
  return 0;
}