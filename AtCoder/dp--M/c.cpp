// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 1e5 + 5;

int n;
int cost[N][3];
int dp[N][3];

int main()
{
  cin >> n;
  for(int i = 0 ; i < n ; i++)
    for(int j = 0 ; j < 3 ; j++)
      cin >> cost[i][j];
  for(int i = 1 ; i <= n ; i++) {
    for(int j = 0 ; j < 3 ; j++) {
      dp[i][j] = 0;
      for(int last = 0; last < 3; last++)
        if(last != j)
          dp[i][j] = max(dp[i][j], dp[i - 1][last] + cost[i - 1][j]);
    }
  }
  cout << max(max(dp[n][0], dp[n][1]), dp[n][2]);
  return 0;
}
