#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int mod = 1e9 + 7;

int n, e;
vector<int> g[N];
int has_leaf[N];
int head[N], nxt[N], to[N], fr[N];
int dp[N][2];

void init(){
	e = 0;
	memset(head, -1, sizeof head);
}

void addEdge(int f, int t){
	nxt[e] = head[f];
	head[f] = e;
	fr[e] = f;
	to[e++] = t;
}

bool DFS(int u, int p){
	has_leaf[u] = 0;
	int len = g[u].size();
	bool is_leaf = 1;
	for(int i = 0; i < len; i++){
		int v = g[u][i];
		if(v != p){
			is_leaf = 0;
			if(DFS(v, u)){
				has_leaf[u] = 1;
			}else{
				addEdge(u, v);
			}
		}
	}
	return is_leaf;
}

int solve(int cur, int need){
	if(cur == -1)
		return !need;
	int& r = dp[cur][need];
	if(r != -1)
		return r;
	int v = to[cur];
	r = 1LL * solve(head[v], 0) * solve(nxt[cur], 0) % mod;
	r += 1LL * solve(head[v], !has_leaf[v]) * solve(nxt[cur], need) % mod;
	r %= mod;
	return r;
}

int solve(){
	memset(dp, -1, sizeof dp);
	return (2LL * solve(head[0], !has_leaf[0])) % mod;
}

int main()
{
	cin >> n;
	init();
	for(int i = 0; i < n - 1; i++){
		int a, b;
		cin >> a >> b;
		--a, --b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	DFS(0, -1);
	cout << solve() << endl;
	return 0;
}