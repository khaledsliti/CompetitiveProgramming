#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 2e3 + 5;
const int V = 1e5 + 5;
const int mod = 1e9 + 7;

int n, m;
int A[N], B[N];
int cntA[V], cntB[V];
int dp[V];

int C[N][N];

void pre()
{
  C[0][0] = 1;
  for(int i = 1 ; i < N ; i++){
    C[i][0] = 1;
    for(int j = 1 ; j <= i ; j++){
      C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
    }
  }
}

int main()
{
  pre();
  cin >> n >> m;
  for(int i = 0 ; i < n ; i++){
    cin >> A[i];
    cntA[A[i]]++;
  }
  for(int j = 0 ; j < m ; j++){
    cin >> B[j];
    cntB[B[j]]++;
  }
  int ans = 1;
  for(int i = 1 ; i < V ; i++){
    int a = cntA[i];
    int b = cntB[i];
    if(a > b) swap(a, b);
    if(!a) continue;
    int sum = 0;
    for(int k = 0 ; k <= a ; k++){
      sum = (sum + 1LL * ((C[a][k] * C[b][k]) % mod) % mod) % mod;
    }
    ans = (ans * 1LL * sum) % mod;
  }
  cout << ans << endl;
  dp[V - 1] = 1;
  for(int i = V - 2 ; i >= 0 ; i--){
    int a = cntA[i];
    int b = cntB[i];
    if(a > b) swap(a, b);
    dp[i] = 0;
    for(int j = 0 ; j <= a ; j++)
      dp[i] = (dp[i] + (((C[a][j] * C[b][j]) % mod) * dp[i + 1]) % mod) % mod;
  }
  cout << dp[0] << endl;
  return 0;
}
