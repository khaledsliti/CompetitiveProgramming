/********************************************************************************************************
  Author: RedStone

  Problem link:
    https://codeforces.com/contest/1175/problem/E

  Idea:
    If we have only one query, then we can find a greedy solution to solve the problem.
    We can try to cover the segemnt [x, y] greedly.
    Let's denote mx[i] the maximum right point of a segment that starts in i.
    Let cur be x. We repete the following step until cur become greater than of equal to y
      * next = max of mx[i] for each i between 0 and cur
      * we stop if next is not greater than cur
      * else cur = next
    If we reach y, then the number of segments that cover segment [x, y] is the number of steps if the above alogithm.
    Now, to solve the problem for a big number of queries we can use a sparse table dp[i][s].
    dp[i][s] is the farthest point we can reach with 2^s steps.\
    Binary search the result for each query to get the minimum number of steps to reach a point >= y.
    For a given query we can get the farthest point using the already built sparse table.

  Complexity:
    Time: O(N (log N) ^ 2)
    Memory: O(N log N)
********************************************************************************************************/
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 5e5 + 8;
const int LOG = 20;

int n, q;
int mx[N];
int dp[N][LOG];

int main()
{
  scanf("%d%d", &n, &q);
  memset(mx, -1, sizeof mx);
  for(int i = 0 ; i < n ; i++){
    int a, b;
    scanf("%d%d", &a, &b);
    mx[a] = max(mx[a], b);
  }
  for(int i = 0 ; i < N ; i++){
    if(i > 0)
      mx[i] = max(mx[i], mx[i - 1]);
    dp[i][0] = mx[i] >= i ? mx[i] : -1;
  }
  for(int l = 1 ; l < LOG ; l++){
    for(int i = 0 ; i < N ; i++){
      if(dp[i][l - 1] != -1)
        dp[i][l] = dp[dp[i][l - 1]][l - 1];
    }
  }
  while(q--){
    int x, y;
    scanf("%d%d", &x, &y);
    int l = 1, r = n, ans = 0;
    while(l <= r){
      int mid = (l + r) / 2;
      int cur = x;
      for(int i = LOG - 1 ; i >= 0 ; i--){
        if(mid & (1 << i)){
          if(cur != -1)
            cur = dp[cur][i];
        }
      }
      if(cur >= y){
        ans = mid;
        r = mid - 1;
      }else{
        l = mid + 1;
      }
    }
    if(ans == 0)
      puts("-1");
    else
      printf("%d\n", ans);
  }
  return 0;
}
