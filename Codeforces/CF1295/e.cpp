#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

#define L(x) (((x) << 1) + 1)
#define R(x) (((x) << 1) + 2)

const int N = 2e5 + 5;

int n;
int per[N], cost[N], pos[N];
long long st[N << 2];
long long lz[N << 2];

void update(int cur, long long val)
{
  st[cur] += val;
  lz[cur] += val;
}

void push_down(int cur, int l, int r)
{
  if(lz[cur]){
    if(l < r){
      update(L(cur), lz[cur]);
      update(R(cur), lz[cur]);
    }
    lz[cur] = 0;
  }
}

void update(int cur, int l, int r, int i, int j, int val)
{
  push_down(cur, l, r);
  if(l > j || r < i)
    return;
  if(l >= i && r <= j){
    update(cur, val);
    return;
  }
  int mid = (l + r) >> 1;
  update(L(cur), l, mid, i, j, val);
  update(R(cur), mid + 1, r, i, j, val);
  st[cur] = min(st[L(cur)], st[R(cur)]);
}

int main()
{
  scanf("%d", &n);
  for(int i = 0 ; i < n ; i++){
    scanf("%d", per + i);
    pos[per[i]] = i;
  }
  for(int i = 0 ; i < n ; i++){
    scanf("%d", cost + per[i]);
  }
  for(int i = 0 ; i < n - 1 ; i++)
    update(0, 0, n - 2, i, n - 2, cost[per[i]]);
  long long best = st[0];
  for(int i = 1 ; i <= n ; i++){
    int c = cost[i];
    update(0, 0, n - 2, pos[i], n - 2, -c);
    if(pos[i] > 0)
      update(0, 0, n - 2, 0, pos[i] - 1, c);
    best = min(best, st[0]);
  }
  cout << best << endl;
  return 0;
}
