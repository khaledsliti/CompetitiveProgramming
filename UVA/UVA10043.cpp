/********************************************************************************************************
  Author: RedStone

  Problem link:
    https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=984

  Idea:
    Any Solution can be a rectangle limited by two points either from bottom and top or left and right.
    We try all possible cases.
    1/ Try all possible values of top and bottom edges among all possible values of y coordinates given in the input. (Don't forget 0)
    Let y1 and y2 be the top and bottom edges (y1 > y2). The answer of in this case (the greatest rectangle's area) is (y1 - y2) * mxLen
    mxLen is defined as follows: we sort all x coordinates of all given points (x, y) such that y2 < y < y2.
    Let's denote this set of points P = {x1, x2, ..., xk}, such that x1 = 0 and xk = W. mxLen = max(xi - xi-1) for all i between 2 and k.
    In other words, we have to get the maximum width of a rectange with top edge y1 and bottom edge y2 such that it does not contain any point inside it.
    To calculate this width, we can represent segment from 0 to W as a set of consecutive segments of length 1.
    For each two consecutive segments, they are connected if and only if there is no point with x coordinate between these two segments.
    Finally we can use UFDS to connect any two consecutive segments.
    To optimize the running time of this algorithm we can process all possible top edges from top to bottom so than after each iteration
    we can union some segments after deleting some points (points that are no longer in the rectangle).
    2/ Reverse the plan and repete step 1 to try all possible values of left and right edges.

  Complexity:
    Time: O(N * W)
    Memory: O(N + W)
********************************************************************************************************/
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
