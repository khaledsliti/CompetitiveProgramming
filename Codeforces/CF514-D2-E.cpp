#include <bits/stdc++.h>
using namespace std;

const int N = 205;
const int mod = 1e9 + 7;

int n;
int cnt[N];
int dp[N], sum[N];
vector<vector<int>> I;

void init()
{
  I.clear();
  for(int i = 0 ; i <= 100 ; i++){
    I.push_back(vector<int>(101));
    for(int j = 0 ; j <= 100 ; j++)
      I[i][j] = i == j;
  }
}

vector<vector<int>> Mult(vector<vector<int>>& A, vector<vector<int>>& B)
{
  assert(A[0].size() == B.size());
  vector<vector<int>> R(A.size(), vector<int>(B[0].size()));
  for(int i = 0 ; i < (int)A.size() ; i++)
    for(int j = 0 ; j < (int)B[0].size() ; j++){
      R[i][j] = 0;
      for(int k = 0 ; k < (int)B.size() ; k++){
        R[i][j] += 1LL * A[i][k] * B[k][j] % mod;
        R[i][j] %= mod;
      }
    }
  return R;
}

vector<vector<int>> Pow(vector<vector<int>>& A, int p)
{
  if(!p)
    return I;
  vector<vector<int>> R = Pow(A, p >> 1);
  R = Mult(R, R);
  if(p & 1)
    R = Mult(R, A);
  return R;
}

int solve(int x)
{
  assert(x >= 100);
  vector<vector<int>> M(101, vector<int>(101, 0));
  M[0][0] = 1;
  for(int i = 1 ; i <= 100 ; i++){
    if(i < 100)
      M[i + 1][i] = 1;
    M[0][i] = M[1][i] = cnt[i];
  }
  M = Pow(M, x - 100);
  int res = 1LL * M[0][0] * sum[100] % mod;
  for(int i = 1 ; i <= 100 ; i++)
    res = (res + 1LL * M[0][i] * dp[101 - i] % mod) % mod;
  return res;
}

int main()
{
  int x;
  init();
  cin >> n >> x;
  for(int i = 0 ; i < n ; i++){
    int a; cin >> a;
    cnt[a]++;
  }
  dp[0] = sum[0] = 1;
  for(int i = 1 ; i <= 200 ; i++){
    for(int j = 1 ; j <= i ; j++)
      dp[i] += 1LL * cnt[j] * dp[i - j] % mod, dp[i] %= mod;
    sum[i] = (sum[i - 1] + dp[i]) % mod;
  }
  if(x <= 100)
    return cout << sum[x] << endl, 0;
  cout << solve(x) << endl;
}