#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 100056;

int L, W;
int n;
int x[N], y[N];
vector<int> pos[N];

int par[N], siz[N], mxSize = 0;
int occ[N];

int fs(int x)
{
  return par[x] == x ? x : par[x] = fs(par[x]);
}

void us(int a, int b)
{
  a = fs(a);
  b = fs(b);
  if(a != b){
    siz[b] += siz[a];
    par[a] = b;
    if(mxSize < siz[b])
      mxSize = siz[b];
  }
}

int solve()
{
  if(n == 0)
    return L * W;
  vector<int> ys = {0};
  for(int i = 0 ; i < n ; i++){
    ys.push_back(y[i]);
    pos[y[i]].push_back(x[i]);
  }
  sort(all(ys));
  ys.resize(unique(ys.begin(), ys.end()) - ys.begin());
  int ans = 0;
  for(int i = 0 ; i < sz(ys) ; i++){
    for(int k = 0 ; k < W ; k++)
      par[k] = k, siz[k] = 1, occ[k] = 0;
    mxSize = 1;
    for(int j = sz(ys) - 1 ; j > i ; j--){
      for(int l = 0 ; l < sz(pos[ys[j]]) ; l++){
        int xi = pos[ys[j]][l];
        occ[xi]++;
      }
    }
    for(int k = 1 ; k < W ; k++){
      if(occ[k] == 0){
        us(k - 1, k);
      }
    }
    ans = max(ans, mxSize * (L - ys[i]));
    for(int j = sz(ys) - 1 ; j > i ; j--){
      for(int l = 0 ; l < sz(pos[ys[j]]) ; l++){
        int xi = pos[ys[j]][l];
        if(!--occ[xi]){
          us(xi - 1, xi);
        }
      }
      ans = max(ans, mxSize * (ys[j] - ys[i]));
    }
    assert(mxSize == W);
  }
  for(int i = 0 ; i < sz(ys) ; i++)
    pos[ys[i]].clear();
  return ans;
}

int main()
{
  int T;
  scanf("%d", &T);
  while(T--){
    scanf("%d%d", &W, &L);
    int k;
    n = 0;
    while(scanf("%d", &k) && k){
      scanf("%d%d", x + n, y + n);
      n++;
      if(--k){
        int dx, dy;
        scanf("%d%d", &dx, &dy);
        while(k--){
          x[n] = x[n - 1] + dx;
          y[n] = y[n - 1] + dy;
          n++;
        }
      }
    }
    {
      int j = 0;
      for(int i = 0 ; i < n ; i++){
        if(x[i] == 0 || x[i] == W || y[i] == 0 || y[i] == L)
          continue;
        x[j] = x[i];
        y[j] = y[i];
        j++;
      }
      n = j;
    }
    int ans = 0;
    for(int it = 0 ; it < 2 ; it++){
      ans = max(ans, solve());
      swap(L, W);
      for(int i = 0 ; i < n ; i++)
        swap(x[i], y[i]);
    }
    printf("%d\n", ans);
  }
  return 0;
}
