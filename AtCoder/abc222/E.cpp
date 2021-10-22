#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;

const int N = 1007, E = 2007;
const int M = 107;
const int Mod = 998244353;
const int V = 1e5 + 5;

int n, m, k, e;
int head[N], to[E], nxt[E], fr[E];
int ord[M];
int cnt[E];
vector<int> cost;
int dp[N][V * 2];

int solve(int i, int acc) {
  if(i >= sz(cost)) {
    return acc == k;
  }
  int& r = dp[i][V + acc];
  if(r != -1) {
    return r;
  }
  return r = (solve(i + 1, acc + cost[i]) + solve(i + 1, acc - cost[i])) % Mod;
}

void init() {
  e = 0;
  memset(head, -1, sizeof head);
}

void addEdge(int f, int t) {
  nxt[e] = head[f];
  head[f] = e;
  to[e] = t;
  fr[e] = f;
  e++;
}

vector<int> getPath(int src, int dst) {
  vector<int> vis(n, 0), par_edge(n, -1);
  vis[src] = 1;
  queue<int> q;
  q.push(src);
  while(!q.empty()) {
    int u = q.front();
    q.pop();
    if(u == dst) {
      break;
    }
    for(int k = head[u]; ~k; k = nxt[k]) {
      int v = to[k];
      if(!vis[v]) {
        vis[v] = 1;
        par_edge[v] = k;
        q.push(v);
      }
    }
  }
  vector<int> path;
  int cur = dst;
  while(par_edge[cur] != -1) {
    path.push_back(par_edge[cur]);
    cur = fr[par_edge[cur]];
  }
  return path;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m >> k;
  for(int i = 0; i < m; i++) {
    cin >> ord[i];
    --ord[i];
  }
  init();
  for(int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    addEdge(a, b);
    addEdge(b, a);
  }
  for(int i = 1; i < m; i++) {
    vector<int> edges = getPath(ord[i - 1], ord[i]);
    for(int e: edges) {
      cnt[e]++;
    }
  }
  for(int i = 0; i < e; i += 2) {
    cost.push_back(cnt[i] + cnt[i + 1]);
  }
  memset(dp, -1, sizeof dp);
  cout << solve(0, 0) << endl;
  return 0;
}
