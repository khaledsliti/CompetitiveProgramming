// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 105;

int n;
long long mat[N][N][N];
long long bit[N][N][N];

void add(int a, int b, int c, int val) {
  for(int i = a ; i <= n ; i += i & -i)
    for(int j = b ; j <= n ; j += j & -j)
      for(int k = c ; k <= n ; k += k & -k)
        bit[i][j][k] += val;
}

long long get(int a, int b, int c) {
  long long r = 0;
  for(int i = a ; i > 0 ; i -= i & -i)
    for(int j = b ; j > 0 ; j -= j & -j)
      for(int k = c ; k > 0 ; k -= k & -k)
        r += bit[i][j][k];
  return r;
}

long long get(int x1, int x2, int y1, int y2, int z1, int z2) {
  return get(x2, y2, z2) - get(x1 - 1, y2, z2) - get(x2, y1 - 1, z2) - get(x2, y2, z1 - 1)
    + get(x1 - 1, y1 - 1, z2) + get(x1 - 1, y2, z1 - 1) + get(x2, y1 - 1, z1 - 1)
    - get(x1 - 1, y1 - 1, z1 - 1);
}

void solve() {
  int q;
  scanf("%d%d", &n, &q);
  for(int i = 0 ; i <= n ; i++)
    for(int j = 0 ; j <= n ; j++)
      for(int k = 0 ; k <= n ; k++)
        bit[i][j][k] = mat[i][j][k] = 0;
  while(q--) {
    char t[10];
    scanf("%s", t);
    if(t[0] == 'U') {
      int x, y, z, v;
      scanf("%d%d%d%d", &x, &y, &z, &v);
      add(x, y, z, v - mat[x][y][z]);
      mat[x][y][z] = v;
    } else {
      int x1, x2, y1, y2, z1, z2;
      scanf("%d%d%d%d%d%d", &x1, &y1, &z1, &x2, &y2, &z2);
      printf("%lld\n", get(x1, x2, y1, y2, z1, z2));
    }
  }
}

int main()
{
  int t;
  scanf("%d", &t);
  while(t--) {
    solve();
  }
  return 0;
}
