// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
typedef long long ll;

const int N = 501, E = 2001;
const int Inf = 1e9 + 5;

int n, m, ID;
int head[N], to[E], fr[E], nxt[E], cap[E], src, snk;
int vis[N];
int e;

void init()
{
  e = 0;
  memset(head, -1, n * (sizeof(head[0])));
}

void addEdge(int f,int t,int w)
{
  nxt[e] = head[f];
  head[f] = e;
  cap[e] = w;
  fr[e] = f;
  to[e++] = t;
}

void addAugEdge(int f,int t,int w)
{
  addEdge(f,t,w);
  addEdge(t,f,0);
}

int dfs(int cur, int snk, int MX, int lowerFlow)
{
  if(vis[cur] == ID || MX == 0) return 0;
  vis[cur] = ID;
  if(cur == snk) return MX;
  for(int i=head[cur] ; i != -1 ; i = nxt[i]){
    if(cap[i] < lowerFlow) continue;
    int t = to[i];
    int f = dfs(t, snk, min(MX, cap[i]), lowerFlow);
    if(!f) continue;
    cap[i] -= f;
    cap[i^1] += f;
    return f;
  }
  return 0;
}

ll maxFlow()
{
  ll ret = 0;
  int f;
  int lo = (1<<30);
  while(lo){
    for(ID++; (f = dfs(src, snk, Inf, lo)); ID++)
      ret += f;
    lo >>= 1;
  }
  return ret;
}

vector<int> getPath() {
  vector<int> path, prv(n, -1);
  queue<int> q;
  q.push(src);
  while(!q.empty()) {
    int u = q.front();
    q.pop();
    if(u == snk) break;
    for(int k = head[u]; ~k; k = nxt[k]) {
      int v = to[k];
      if(cap[k] == 0 && v != src && prv[v] == -1 && k % 2 == 0) {
        prv[v] = k;
        q.push(v);
      }
    }
  }
  assert(prv[snk] != -1);
  for(int k = prv[snk]; k != -1; k = prv[fr[k]]) {
    path.pb(k);
    cap[k] = 1;
  }
  reverse(all(path));
  return path;
}

int main()
{
  cin >> n >> m;
  init();
  for(int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    addAugEdge(a, b, 1);
  }
  src = 0, snk = n - 1;
  int flow = maxFlow();
  cout << flow << endl;
  for(int it = 0; it < flow; it++) {
    auto path = getPath();
    cout << sz(path) + 1 << endl;
    cout << 1;
    for(int x : path)
      cout << " " << to[x] + 1;
    cout << endl;
  }
  return 0;
}
