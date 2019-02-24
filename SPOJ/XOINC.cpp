/********************************************************************************************************
  Author: RedStone

  Problem link:
    https://www.spoj.com/problems/XOINC/

  Idea:
    At first, let diff = current_player - next_player and sum_of_element be the sum of all elements.
    So, current_player = (diff + sum_of_element) / 2.
    Here we use a dp solution to calculate the maximum possible diff.
    dp[i][j] is the maximum possible diff using element from i to n and the current player can take up to j elements.
    dp[i][j] = Max( sum(i, i + k - 1) - dp[i + k][2 * k] ) such that 1 <= k <= j
    To find this Max we can write a for loop in each state (i, j) but this will give TLE (O(N^3)).
    So we need to reduce it to O(N^2).
    For each k between 1 and j - 1, we can find the best solution in dp[i][j - 1] because we take less than j elements in this case.
    Finally the best solution for state (i, j) is max(dp[i][j - 1], sum(i, i + j - 1) - dp[i + j][2 * j]).

  Compexity:
    Time: O(N^2)
    Memory: O(N^2)
********************************************************************************************************/
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
typedef long long ll;
const int oo = 1e9;
const int mod = 1e9 + 7;

const int N = 2005;

int n;
int arr[N], pref[N];
int dp[N][N];

int get(int i, int j)
{
  return pref[j] - pref[i - 1];
}

int main()
{
  scanf("%d", &n);
  for(int i = 1 ; i <= n ; i++){
    scanf("%d", arr + i);
    pref[i] = arr[i] + pref[i - 1];
  }
  for(int i = n ; i ; i--){
    for(int j = 1 ; j <= n ; j++){
      int rem = n - i + 1;
      if(rem <= j){
        dp[i][j] = get(i, n);
      }else{
        dp[i][j] = get(i, i + j - 1) - dp[i + j][min(n, 2 * j)];
        if(j > 1)
          dp[i][j] = max(dp[i][j - 1], dp[i][j]);
      }
    }
  }
  printf("%d\n", (dp[1][2] + get(1, n)) / 2);
  return 0;
}
