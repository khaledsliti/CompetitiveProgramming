#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int mod = 1e9 + 7;

int n, e;
vector<int> g[N];
int head[N], nxt[N], to[N];
int dp[N][2];

void init(){
	e = 0;
	memset(head, -1, sizeof head);
}

void addEdge(int f, int t){
	nxt[e] = head[f];
	head[f] = e;
	to[e++] = t;
}

void DFS(int u, int p){
	int len = g[u].size();
	for(int i = 0; i < len; i++){
		int v = g[u][i];
		if(v != p){
			DFS(v, u);
			addEdge(u, v);
		}
	}
}

int solve(int cur, int need){
	if(cur == -1)
		return !need;
	int& r = dp[cur][need];
	if(r != -1)
		return r;
	int v = to[cur];
	r = 1LL * solve(head[v], 0) * solve(nxt[cur], 0) % mod;
	r += 1LL * solve(head[v], 1) * solve(nxt[cur], need) % mod;
	r %= mod;
	return r;
}

int solve(){
	memset(dp, -1, sizeof dp);
	return (2LL * solve(head[0], 1)) % mod;
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