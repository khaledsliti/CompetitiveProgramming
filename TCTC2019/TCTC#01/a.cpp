/********************************************************************************************************
  Author: RedStone

  Problem link:
     https://codeforces.com/group/HtnK54FR7R/contest/262699/problem/A

  Idea:

  Complexity:
    Time:
    Memory:
********************************************************************************************************/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) begin(x), end(x)

const int N = (1 << 17) + 1;

int n, q;
int sol[N];
vector<int> add[N], del[N];
int bit[N];

void update(int idx, int val)
{
  for( ; idx < N ; idx += idx & -idx)
    bit[idx] += val;
}

int kth(int k)
{
  if(bit[N - 1] < k)
    return -1;
  int l = 1, r = N - 1;
  while(l < r){
    int mid = l + r >> 1;
    if(bit[mid] >= k){
      r = mid;
    }else{
      k -= bit[mid];
      l = mid + 1;
    }
  }
  return l;
}

int main()
{
  scanf("%d%d", &n, &q);
  for(int i = 0 ; i < n ; i++){
    int l, r;
    scanf("%d%d", &l, &r);
    add[l].push_back(i + 1);
    del[r + 1].push_back(i + 1);
  }
  for(int i = 1 ; i <= n ; i++){
    for(int p : add[i])
      update(p, 1);
    for(int p : del[i])
      update(p, -1);
    sol[i] = kth(i);
  }
  while(q--){
    int cnt;
    scanf("%d", &cnt);
    printf("%d\n", sol[cnt]);
  }
  return 0;
}
