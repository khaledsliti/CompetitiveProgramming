// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 1e5 + 5;
const long long oo = 1e18;
const int P = 7;

int n, p, k;
int a[N];
int po[N][P];
int perm[N];
long long dp[N][1 << P];
bool vis[N][1 << P];

long long solve(int cur, int mask, int cnt)
{
  if(cur >= n) {
    assert(cnt == p);
    return 0;
  }
  long long& r = dp[cur][mask];
  if(vis[cur][mask]) return r;
  vis[cur][mask] = 1;
  r = -oo;
  int prev = cur - cnt;
  int rem = n - cur - 1;
  if(rem + cnt >= p)
    r = (prev < k ? a[perm[cur]] : 0) + solve(cur + 1, mask, cnt);
  if(cnt < p) {
    for(int i = 0 ; i < p ; i++) {
      if(!(mask & (1 << i))) {
        r = max(r, po[perm[cur]][i] + solve(cur + 1, mask | (1 << i), cnt + 1));
      }
    }
  }
  return r;
}

int main()
{
  scanf("%d%d%d", &n, &p, &k);
  for(int i = 0 ; i < n ; i++)
    scanf("%d", a + i);
  for(int i = 0 ; i < n ; i++)
    for(int j = 0 ; j < p ; j++)
      scanf("%d", &po[i][j]);
  iota(perm, perm + n, 0);
  sort(perm, perm + n, [](int i, int j){
    return a[i] > a[j];
  });
  memset(vis, 0, sizeof vis);
  cout << solve(0, 0, 0) << endl;
  return 0;
}
