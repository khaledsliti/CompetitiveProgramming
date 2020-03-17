// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 15;
const long long oo = 1e15;

int n, m, t, k;
int c[N][N];
vector<int> g[N];
long long cost[1 << N][N];
long long mem[1 << N][N];

long long calc(int idx, int mask) {
  vector<int> a;
  for(int i = 0 ; i < t ; i++) {
    if(mask & (1 << i)) {
      for(int v : g[i]) {
        a.push_back(v);
      }
    }
  }
  sort(all(a));
  long long res = 0;
  for(int i = n - 1 ; i >= 0 && sz(a) ; i--) {
    for(int it = 0 ; it < k && sz(a) ; it++) {
      res += 1LL * c[idx][i] * a.back();
      a.pop_back();
    }
  }
  if(sz(a)) return -1;
  else return res;
}

long long solve(int cur, int mask) {
  if(cur >= m) return !mask ? 0 : -oo;
  long long& res = mem[mask][cur];
  if(res != -1) return res;
  res = solve(cur + 1, mask);
  for(int subm = mask ; subm ; subm = (subm - 1) & mask) {
    if(~cost[subm][cur])
      res = max(res, cost[subm][cur] + solve(cur + 1, mask ^ subm));
  }
  return res;
}

string print_mask(int m, int t) {
  string r = "";
  for(int i = 0 ; i < t ; i++) {
    if(m & (1 << i)) r += '1';
    else r += '0';
  }
  return r;
}

void solve() {
  scanf("%d%d%d", &m, &n, &t);
  for(int i = 0 ; i < m ; i++) {
    for(int j = 0 ; j < n ; j++)
      scanf("%d", &c[i][j]);
    sort(c[i], c[i] + n);
  }
  for(int i = 0 ; i < t ; i++) {
    int x; scanf("%d", &x);
    g[i].clear();
    while(x--) {
      int a; scanf("%d", &a);
      g[i].push_back(a);
    }
  }
  scanf("%d", &k);
  for(int i = 0 ; i < m ; i++) {
    cost[0][i] = 0;
    for(int mask = 1 ; mask < (1 << t) ; mask++) {
      cost[mask][i] = calc(i, mask);
    }
  }
  memset(mem, -1, sizeof mem);
  long long ans = solve(0, (1 << t) - 1);
  if(ans < 0) ans = -1;
  printf("%lld\n", ans);
}

int main()
{
  int T;
  scanf("%d", &T);
  while(T--) {
    solve();
  }
  return 0;
}
