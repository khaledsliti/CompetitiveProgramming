/********************************************************************************************************
  Author: RedStone

  Problem link:
  	https://codeforces.com/contest/834/problem/D

  Idea:
  	In this problem, we need to divide the array into K segment with maximum sum of scores.
  	The score of a segment is the number of distinct elements inside it.
  	We can solve the problem using a dp approach.
  	Let's dp[i][j] be the optimal solution for elements from 1 to j using i segments.
  	We can easily see that dp[1][j] is the number of distinct elements from 1 to j.
		dp[i][j] = Max( dp[i - 1][k - 1] + dist(k, j) ) for all k from 1 to j, where dist(a, b) is the number of distinct elements from a to b.
		Now, we can calculate this easily in O(N * N * K) but this will give TLE.
		So, to reduce the time complexity of this solution we will use a segment tree for each i to calculate Max( dp[i - 1][k - 1] + dist(k, j) ).
		Let's start by storing dp[i - 1] in the segment tree. dp[i][0] = inf.
		For each j between 1 and N, we add 1 to the range from the last occurrence of arr[j] and j - 1,
		because dist(k, j) increase by 1 for each k in this range.
		Finally, we must get the max using the segment tree to calculate dp[i][j].

  Compexity:
  	Time: O(N * K * log(N))
  	Memory: O(N * K * log(N))
********************************************************************************************************/
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
typedef long long ll;

const int oo = 1e9;
const int N = 35001, K = 51;

int n, k;
int arr[N];
int dp[K][N];
int st[4 * N], lz[4 * N];
int last[N];

void build(int idx, int node, int s, int e)
{
  lz[node] = 0;
  if(s == e){
    st[node] = dp[idx][s];
    return;
  }
  int mid = (s + e) / 2;
  int l = 2 * node + 1;
  int r = 2 * node + 2;
  build(idx, l, s, mid);
  build(idx, r, mid + 1, e);
  st[node] = max(st[l], st[r]);
}

void push_down(int node, int s, int e)
{
  if(lz[node]){
    st[node] += lz[node];
    if(s != e){
      int l = 2 * node + 1;
      int r = 2 * node + 2;
      lz[l] += lz[node];
      lz[r] += lz[node];
    }
    lz[node] = 0;
  }
}

void update(int node, int s, int e, int i, int j, int val)
{
  push_down(node, s, e);
  if(s > j || e < i)
    return;
  int l = 2 * node + 1;
  int r = 2 * node + 2;
  if(s >= i && e <= j){
    st[node] += val;
    if(s != e){
      lz[l] += val;
      lz[r] += val;
    }
    return;
  }
  int mid = (s + e) / 2;
  update(l, s, mid, i, j, val);
  update(r, mid + 1, e, i, j, val);
  st[node] = max(st[l], st[r]);
}

int query(int node, int s, int e, int i, int j)
{
  push_down(node, s, e);
  if(s > j || e < i)
    return -oo;
  if(s >= i && e <= j)
    return st[node];
  int mid = (s + e) / 2;
  int l = 2 * node + 1;
  int r = 2 * node + 2;
  return max(query(l, s, mid, i, j), query(r, mid + 1, e, i, j));
}

int main()
{
  ios::sync_with_stdio(false);
  cin >> n >> k;
  for(int i = 1 ; i <= n ; i++)
    cin >> arr[i];
  for(int j = 1 ; j <= n ; j++)
    dp[0][j] = -oo;
  build(0, 0, 0, n);
  for(int i = 1 ; i <= k ; i++){
    memset(last, 0, sizeof last);
    dp[i][0] = -oo;
    for(int j = 1 ; j <= n ; j++){
      int cur = arr[j];
      update(0, 0, n, last[cur], j - 1, 1);
      dp[i][j] = query(0, 0, n, 0, j - 1);
      last[cur] = j;
    }
    build(i, 0, 0, n);
  }
  cout << dp[k][n] << endl;
  return 0;
}
