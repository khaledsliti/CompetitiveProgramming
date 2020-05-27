#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) begin(x), end(x)

const int N = 2001;

int n, m, q;
long long bit[N][N];

void add(int i, int j, int val)
{
  for(int r = i; r < N ; r += r & -r)
    for(int c = j; c < N ; c += c & -c)
      bit[r][c] += val;
}

long long sum(int i, int j)
{
  long long s = 0;
  for(int r = i; r > 0 ; r -= r & -r)
    for(int c = j; c > 0 ; c -= c & -c)
      s += bit[r][c];
  return s;
}

int main()
{
  scanf("%d%d%d", &n, &m, &q);
  for(int i = 1 ; i <= n ; i++)
    for(int j = 1, a ; j <= m ; j++){
      scanf("%d", &a);
      add(i, j, a);
    }
  while(q--){
    int t;
    scanf("%d", &t);
    if(t == 1){
      int x, y, v;
      scanf("%d%d%d", &x, &y, &v);
      add(x, y, v);
    }else{
      int l, r, u, d;
      scanf("%d%d%d%d", &u, &l, &d, &r);
      printf("%lld\n", sum(d, r) - sum(u - 1, r) - sum(d, l - 1) + sum(u - 1, l - 1));
    }
  }
  return 0;
}
