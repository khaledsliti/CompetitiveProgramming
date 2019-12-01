/********************************************************************************************************
  Author: RedStone

  Problem link:
    https://codeforces.com/gym/100212/attachments

  Idea:
    We can solve the problem using a dp technique. The main idea is to process the grid column by column from left to right.
    For each column we places peaces until it becames completely full.
    So the state of the dp is the current column j and the current state of the columns j, j + 1 and j + 2.
    We can use an integer in base 4 to represent the second parameter of the state.

  Compexity:
    Time: O(N * M * 4^N)
    Memory: O(M * 4^N)
********************************************************************************************************/
#include <bits/stdc++.h>
using namespace std;

int n, m;
long long dp[30][262144];

int getNextState(int row, int* state_array)
{
  int res = 0;
  for(int i = n - 1 ; i >= 0 ; i--)
    res = res * 4 + state_array[i] - (row + 1 == n);
  return res;
}

long long solve(int j, int state){
  if(j >= m)
    return 1;
  long long& r = dp[j][state];
  if(r != -1)
    return r;
  r = 0;
  int cur_state[n];
  for(int k = 0 ; k < n ; k++){
    cur_state[k] = state % 4;
    state /= 4;
  }
  int i = 0;
  while(i < n && cur_state[i] != 0) i++;
  if(i >= n)
    return r = solve(j + 1, getNextState(n - 1, cur_state));
  // horizontal
  if(j + 2 < m){
    cur_state[i] = 3;
    r += solve(j + (i + 1) / n, getNextState(i, cur_state));
  }
  // vertical
  if(i + 2 < n && cur_state[i + 1] == 0 && cur_state[i + 2] == 0){
    cur_state[i] = cur_state[i + 1] = cur_state[i + 2] = 1;
    r += solve(j + (i + 1) / n, getNextState(i, cur_state));
  }
  return r;
}

int main()
{
  freopen("dominoes.in", "r", stdin);
  freopen("dominoes.out", "w", stdout);
  cin >> n >> m;
  assert(n <= 9 && m <= 30);
  memset(dp, -1, sizeof dp);
  cout << solve(0, 0) << endl;
  return 0;
}
