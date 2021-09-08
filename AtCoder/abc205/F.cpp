// Guess Who's Back
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

const int oo = (int) 1e9;
const int N = 2000001, E = 4001000;


int x, r, c;
int adj[101][101];

int n,ID;
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

int maxFlow()
{
	int ret = 0;
	int f;
	int lo = (1<<30);
	while(lo){
		for(ID++; (f = dfs(src, snk, oo, lo)); ID++)
			ret += f;
		lo >>= 1;
	}
	return ret;
}

void print() {
  for(int i = 0; i < n; i++) {
    cout << i << ": ";
    for(int k = head[i]; ~k; k = nxt[k]) {
      cout << to[k] << " ";
    }
    cout << endl;
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> r >> c >> x;

  n = 2 + x + 2 * r * c + r + c;

  init();
  src = 0, snk = n - 1;

  // from src to nodes
  for(int i = 1; i <= x; i++) {
    addAugEdge(src, i, 1);
  }

  // from node to cell in
  for(int k = 0; k < x; k++) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    --a, --b, --c, --d;
    for(int i = a; i <= c; i++) {
      for(int j = b; j <= d; j++) {
        int idx = i * ::c + j;
        addAugEdge(k + 1, x + 1 + idx, 1);
      }
    }
  }

  // from in to out
  for(int i = 0; i < r; i++) {
    for(int j = 0; j < c; j++) {
      int idx = i * c + j;
      addAugEdge(x + 1 + idx, x + 1 + r * c + idx, 1);
    }
  }

  // from out to row and col
  for(int i = 0; i < r; i++) {
    for(int j = 0; j < c; j++) {
      int idx = i * c + j;
      addAugEdge(x + 1 + r * c + idx, x + 1 + 2 * r * c + i, 1);
      addAugEdge(x + 1 + r * c + idx, x + 1 + 2 * r * c + r + j, 1);
    }
  }

  // from row to snk
  for(int i = 0; i < r; i++) {
    addAugEdge(x + 1 + 2 * r * c + i, snk, 1);
  }

  // from col to snk
  for(int i = 0; i < c; i++) {
    addAugEdge(x + 1 + 2 * r * c + r + i, snk, 1);
  }

  print();
  
  cout << maxFlow() << endl;

  return 0;
}
