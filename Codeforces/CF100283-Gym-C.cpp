/********************************************************************************************************
  Author: RedStone

  Problem link:
    https://codeforces.com/gym/100283/problem/C

  Idea:

  Compexity:
    Time: O(N * M * S) for each test
    Memory: O(N * M)
********************************************************************************************************/
#include <bits/stdc++.h>
using namespace std;
#define mp make_pair

const int N = 204;
const int mod = 1e9 + 7;

int n, m, s;
int dp[N][N];
int pref[N][N];
int forbidden[N][N];

void init(int nmax)
{
  for(int i = 0 ; i < nmax ; i++)
    for(int j = 0 ; j < nmax ; j++){
      dp[i][j] = 0;
      forbidden[i][j] = 1;
    }
}

int get(int u, int d, int l, int r)
{
  int sum = pref[d][r];
  if(u > 0)
    sum = (sum - pref[u - 1][r]) % mod;
  if(l > 0)
    sum = (sum - pref[d][l - 1]) % mod;
  if(u > 0 && l > 0)
    sum = (sum + pref[u - 1][l - 1]) % mod;
  return sum;
}

int main()
{
  freopen("treasures.in", "r", stdin);
  int T, tc(1);
  scanf("%d", &T);
  while(T--){
    int pi, pj;
    printf("Case %d: ", tc++);
    scanf("%d%d%d%d%d", &n, &m, &s, &pi, &pj);
    init(n + m - 1);
    for(int i = 0 ; i < n ; i++){
      for(int j = 0 ; j < m ; j++){
        int a;
        scanf("%d", &a);
        dp[i + j][m - 1 + i - j] = a;
        forbidden[i + j][m - 1 + i - j] = 0;
      }
    }
    n += m - 1;
    for(int t = 1 ; t < s ; t++){
      for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < n ; j++){
          pref[i][j] = dp[i][j];
          if(i > 0)
            pref[i][j] = (pref[i][j] + pref[i - 1][j]) % mod;
          if(j > 0)
            pref[i][j] = (pref[i][j] + pref[i][j - 1]) % mod;
          if(i > 0 && j > 0)
            pref[i][j] = (pref[i][j] - pref[i - 1][j - 1]) % mod;
        }
      for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
          if(forbidden[i][j])
            dp[i][j] = 0;
          else{
            int u = max(0, i - t);
            int d = min(n - 1, i + t);
            int l = max(0, j - t);
            int r = min(n - 1, j + t);
            dp[i][j] = get(u, d, l, r);
          }
        }
      }
    }
    --pi, --pj;
    printf("%d\n", (dp[pi + pj][m - 1 + pi - pj] + mod) % mod);
  }
  return 0;
}
