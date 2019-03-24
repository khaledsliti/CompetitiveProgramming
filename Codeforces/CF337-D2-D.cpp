#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int)(x).size())

const int N = 1e5 + 2;

int n, m, d;
vector<int> g[N];
vector<int> pref[N], suff[N];
int marked[N];
int in[N], out[N], par[N], mxb[N];

// Calc in
void DFS(int u, int p)
{
	par[u] = p;
	in[u] = marked[u] ? 0 : -1;
	for(int i = 0 ; i < sz(g[u]) ; i++){
		int v = g[u][i];
		if(v != p){
			DFS(v, u);
			if(in[v] > -1)
				in[u] = max(in[u], 1 + in[v]);
		}
	}
}

// Calc out
void DFS(int u)
{
	out[u] = marked[u] ? 0 : -1;
	int p = par[u];
	if(p > -1){
		if(out[p] > -1)
			out[u] = max(out[u], 1 + out[p]);
		if(mxb[u] > -1)
			out[u] = max(out[u], 2 + mxb[u]);
	}
	for(int i = 0 ; i < sz(g[u]) ; i++){
		int v = g[u][i];
		if(v != par[u])
			DFS(v);
	}
}

int main()
{
	cin >> n >> m >> d;
	for(int i = 0 ; i < m ; i++){
		int a;
		cin >> a;
		marked[--a] = 1;
	}
	for(int i = 0 ; i < n - 1 ; i++){
		int u, v;
		cin >> u >> v;
		--u, --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	DFS(0, -1);
	for(int i = 0 ; i < n ; i++){
		int len = sz(g[i]);
		int mx1 = -1, mx2 = -1;
		for(int j = 0 ; j < len ; j++){
			int v = g[i][j];
			if(v == par[i])
				continue;
			int c = in[v];
			if(c > mx1){
				mx2 = mx1;
				mx1 = c;
			}else if(c > mx2)
				mx2 = c;
		}
		for(int j = 0 ; j < len ; j++){
			int v = g[i][j];
			if(v == par[i])
				continue;
			int c = in[v];
			if(c == mx1)
				mxb[v] = mx2;
			else
				mxb[v] = mx1;
		}
	}
	DFS(0);
	int ans = 0;
	for(int i = 0 ; i < n ; i++)
		ans += max(in[i], out[i]) <= d;
	cout << ans << endl;
	return 0;
}