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
int head[N], to[E], nxt[E], cap[E], src, snk;
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

int main()
{
  cin >> n >> m;
  init();
  for(int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    addEdge(a, b, 1);
    addEdge(b, a, 1);
  }
  src = 0, snk = n - 1;
  cout << maxFlow() << endl;
  queue<int> q;
  q.push(src);
  ID++;
  vis[src] = ID;
  while(!q.empty()) {
    int u = q.front();
    q.pop();
    if(u == n - 1) continue;
    for(int k = head[u]; ~k; k = nxt[k]) {
      int v = to[k];
      if(cap[k] && vis[v] != ID) {
        vis[v] = ID;
        q.push(v);
      }
    }
  }
  for(int i = 0; i < n; i++) {
    for(int k = head[i]; ~k; k = nxt[k]) {
      int j = to[k];
      if(vis[i] == ID && !cap[k] && vis[j] != ID) {
        cout << i + 1 << " " << j + 1 << endl;
      }
    }
  }
  return 0;
}
