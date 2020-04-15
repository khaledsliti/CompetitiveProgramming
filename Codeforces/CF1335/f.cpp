// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 1000007;

int n;
int col[N], nxt[N];
vector<int> prv[N];
char line[N];
int vis[N];

void dfs(int u, set<int>& val, int len, int lev, int src) {
  if(!col[u]) val.insert(lev);
  vis[u] = 1;
  for(int v : prv[u])
    if(v != src) {
      dfs(v, val, len, (lev + 1) % len, src);
    }
}

void solve() {
  int r, c;
  scanf("%d%d", &r, &c);
  n = r * c;
  for(int i = 0 ; i < r ; i++) {
    scanf("%s", line);
    for(int j = 0 ; j < c ; j++) {
      col[i * c + j] = line[j] - '0';
    }
  }
  for(int i = 0 ; i < n ; i++) {
    vis[i] = 0;
    nxt[i] = -1;
    prv[i].clear();
  }
  for(int i = 0 ; i < r ; i++) {
    scanf("%s", line);
    for(int j = 0 ; j < c ; j++) {
      int u = i * c + j, v;
      char d = line[j];
      if(d == 'U') v = (i - 1) * c + j;
      if(d == 'D') v = (i + 1) * c + j;
      if(d == 'L') v = i * c + j - 1;
      if(d == 'R') v = i * c + j + 1;
      nxt[u] = v;
      prv[v].pb(u);
    }
  }
  int tot = 0, blacks = 0;
  for(int i = 0 ; i < n ; i++) {
    if(!vis[i]) {
      int src = i;
      while(vis[src] == 0) {
        vis[src] = 1;
        src = nxt[src];
      }
      int len = 0, cur = src;
      do{
        len++;
        cur = nxt[cur];
      } while(cur != src);
      tot += len;
      set<int> val;
      dfs(cur, val, len, 0, cur);
      blacks += sz(val);
    }
  }
  printf("%d %d\n", tot, blacks);
}

int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
    solve();
  return 0;
}
