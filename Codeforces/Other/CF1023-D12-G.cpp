#include <bits/stdc++.h>
using namespace std;

const int oo = 1e9;
const int mod = 1e9 + 7;
const int N = 2e5 + 6;

int n, q, k;
int A[N][5];
int B[N][5];
int idx[N], t[N];
int ans[N];
pair<int, int> st[4 * N];

void build(int cur, int s, int e, int mask)
{
  if(s == e){
    int sum = 0;
    for(int j = 0 ; j < k ; j++){
      int sign = (mask >> j) & 1;
      sum += (sign ? 1 : -1) * A[s][j];
    }
    st[cur] = { sum, sum };
    return;
  }
  int mid = (s + e) / 2;
  int l = 2 * cur + 1;
  int r = 2 * cur + 2;
  build(l, s, mid, mask);
  build(r, mid + 1, e, mask);
  st[cur].first = max(st[l].first, st[r].first);
  st[cur].second = min(st[l].second, st[r].second);
}

void update(int cur, int s, int e, int idx, int val)
{
  if(s > idx || e < idx)
    return;
  if(s == e){
    st[cur] = { val, val };
    return;
  }
  int mid = (s + e) / 2;
  int l = 2 * cur + 1;
  int r = 2 * cur + 2;
  update(l, s, mid, idx, val);
  update(r, mid + 1, e, idx, val);
  st[cur].first = max(st[l].first, st[r].first);
  st[cur].second = min(st[l].second, st[r].second);
}

pair<int, int> query(int cur, int s, int e, int i, int j)
{
  if(s > j || e < i)
    return { -oo, oo };
  if(s >= i && e <= j)
    return st[cur];
  int mid = (s + e) / 2;
  pair<int, int> a = query(2 * cur + 1, s, mid, i, j);
  pair<int, int> b = query(2 * cur + 2, mid + 1, e, i, j);
  return { max(a.first, b.first), min(a.second, b.second) };
}

int main()
{
  scanf("%d%d", &n, &k);
  for(int i = 0 ; i < n ; i++)
    for(int j = 0 ; j < k ; j++)
      scanf("%d", &A[i][j]); 
  scanf("%d", &q);
  for(int i = 0 ; i < q ; i++){
    scanf("%d", &t[i]);
    if(t[i] == 2){
      scanf("%d%d", &B[i][0], &B[i][1]);
      B[i][0]--;
      B[i][1]--;
    }else{
      scanf("%d", &idx[i]);
      idx[i]--;
      for(int j = 0 ; j < k ; j++)
        scanf("%d", &B[i][j]);
    }
  }
  for(int mask = 0 ; mask < (1 << k) ; mask++){
    build(0, 0, n - 1, mask);
    for(int i = 0 ; i < q ; i++){
      if(t[i] == 1){
        int sum = 0;
        for(int j = 0 ; j < k ; j++){
          int sign = (mask >> j) & 1;
          sum += (sign ? 1 : -1) * B[i][j];
        }
        update(0, 0, n - 1, idx[i], sum);
      }else{
        pair<int, int> res = query(0, 0, n - 1, B[i][0], B[i][1]);
        ans[i] = max(ans[i], res.first - res.second);
      }
    }
  }
  for(int i = 0 ; i < q ; i++)
    if(t[i] == 2)
      printf("%d\n", ans[i]);
  return 0;
}
