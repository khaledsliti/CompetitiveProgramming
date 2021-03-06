#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
const long long oo = 2e18;

int n;
long long arr[N];
pair<long long, int> st[4 * N];
long long lz[4 * N];
int ans[N];

void merge(int cur, int l,  int r)
{
  if(st[l].first < st[r].first){
    st[cur] = st[l];
  }else{
    st[cur] = st[r];
  }
}

void build(int cur, int s, int e)
{
  if(s == e){
    st[cur] = { arr[s], s };
    return;
  }
  int mid = (s + e) / 2;
  int l = 2 * cur + 1;
  int r = 2 * cur + 2;
  build(l, s, mid);
  build(r, mid + 1, e);
  merge(cur, l, r);
}

void push_down(int cur, int s, int e)
{
  if(lz[cur]){
    int l = 2 * cur + 1;
    int r = 2 * cur + 2;
    if(s != e){
      lz[l] += lz[cur];
      lz[r] += lz[cur];
    }
    st[cur].first += lz[cur];
    lz[cur] = 0;
  }
}

void update(int cur, int s, int e, int i, int j, long long val)
{
  push_down(cur, s, e);
  if(s > j || e < i)
    return;
  int l = 2 * cur + 1;
  int r = 2 * cur + 2;
  int mid = (s + e) / 2;
  if(s >= i && e <= j){
    st[cur].first += val;
    if(s != e){
      lz[l] += val;
      lz[r] += val;
    }
    return;
  }
  update(l, s, mid, i, j, val);
  update(r, mid + 1, e, i, j, val);
  merge(cur, l, r);
}

int query()
{
  push_down(0, 1, 2);
  return st[0].second;
}

int main()
{
  scanf("%d", &n);
  for(int i = 0 ; i < n ; i++)
    scanf("%I64d", arr + i);
  build(0, 0, n - 1);
  for(int cur = 1 ; cur <= n ; cur++){
    int idx = query();
    ans[idx] = cur;
    if(idx + 1 < n)
      update(0, 0, n - 1, idx + 1, n - 1, -cur);
    update(0, 0, n - 1, idx, idx, oo);
  }
  for(int i = 0 ; i < n ; i++)
    printf("%d ", ans[i]);
  return 0;
}