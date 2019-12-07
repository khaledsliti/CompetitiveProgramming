#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) begin(x), end(x)

const int L = 17;
const int N = 1 << L;

int n, q;
int dp[N][L];
int lg[N];

inline int query(int i, int j)
{
  int len = j - i + 1;
  assert(i + (1 << lg[len]) - 1 <= j);
  return min(dp[i][lg[len]], dp[j - (1 << lg[len]) + 1][lg[len]]);
}

int main()
{
  lg[1] = 0;
  for(int i = 2 ; i < N ; i++)
    lg[i] = 1 + lg[i >> 1];
  scanf("%d", &n);
  for(int i = 0 ; i < n ; i++)
    scanf("%d", &dp[i][0]);
  for(int len = 1 ; (1 << len) <= n ; len++)
    for(int i = 0 ; i + (1 << len) <= n ; i++)
      dp[i][len] = min(dp[i][len - 1], dp[i + (1 << (len - 1))][len - 1]);
  scanf("%d", &q);
  while(q--){
    int i, j;
    scanf("%d%d", &i, &j);
    printf("%d\n", query(i, j));
  }
  return 0;
}
