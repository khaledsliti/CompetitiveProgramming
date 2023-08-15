#include <bits/stdc++.h>
using namespace std;
const int N=100000;
int n;
vector<vector<pair<int,int> > > g;
int v[N];
map<int,vector<int> > at;
int d[N];
int dp[20][N];
int target,mx;
int res[N];
vector<int> edges;
bool good[N];
bool DFS(int u,int p){
	dp[0][u] = p;
	int found=u==target;
	for(auto &e:g[u])
		if(e.first!=p){
			int v=e.first;
			d[v] = d[u]+1;
			if(!DFS(v, u))
				res[e.second] = mx;
			else{
				found=true;
				edges.push_back(e.second);
			}
		}
	good[u] = found;
	return found;
}
int LCA(int u,int v){
	if(d[u]<d[v])
		swap(u, v);
	int l=0;
	while((1<<l)<=d[u])
		++l;
	--l;
	for(int i=l;i>=0;--i)
		if(d[u] - (1<<i) >= d[v])
			u=dp[i][u];
	if(u==v)
		return u;
	for(int i=l;i>=0;--i)
		if(dp[i][u]!=dp[i][v]){
			u=dp[i][u];
			v=dp[i][v];
		}
	return dp[0][u];
}
int firstGood(int u){
	if(good[u])
		return u;
	for(int i=19;i>=0;--i)
		if(dp[i][u] != -1 && !good[dp[i][u]])
			u = dp[i][u];
	return dp[0][u];
}
int main() {
	scanf("%d",&n);
	g.resize(n);
	for(int i=0,a,b;i<n-1;++i){
		scanf("%d%d",&a,&b);
		--a;--b;
		g[a].push_back({b, i});
		g[b].push_back({a, i});
	}
	mx=0;
	for(int i=0;i<n;++i){
		scanf("%d",&v[i]);
		at[v[i]].push_back(i);
		if(mx<v[i] && at[v[i]].size()>=2)
			mx=v[i];
	}
	if(mx == 0 || at[mx].size()>=3){
		for(int i=0;i<n-1;++i)
			printf("%d\n",mx);
		return 0;
	}
	memset(dp,-1,sizeof(dp));
	target = at[mx][1];
	DFS(at[mx][0], -1);
	reverse(edges.begin(),edges.end());
	for(int k=1;(1<<k)<n;++k)
		for(int u=0;u<n;++u)
			if(dp[k-1][u]!=-1)
				dp[k][u] = dp[k-1][dp[k-1][u]];
	vector<vector<int>> in(edges.size()), out(edges.size());
	for(auto it=at.rbegin(); it!=at.rend(); ++it){
		auto loc = it->second;
		int val = it->first;
		if(loc.size()<2 || val == mx){
			continue;
		}
		int u=loc[0], v=loc[1];
		u=firstGood(u);
		v=firstGood(v);
		if(loc.size()>2 || !good[LCA(u,v)] || u==v){
			in[0].push_back(val);
			break;
		}
		if(d[u]>d[v])
			swap(u,v);
		if(d[u] != 0){
			in[0].push_back(val);
			out[d[u]].push_back(val);
		}
		if(d[v] != edges.size())
			in[d[v]].push_back(val);
	}
	multiset<int> s;
	for(int i=0;i<in.size();++i){
		for(auto &x:in[i])
			s.insert(x);
		for(auto &x:out[i])
			s.erase(s.find(x));
		if(!s.empty())
			res[edges[i]] = max(res[edges[i]], *--s.end());
	}
	for(int i=0;i<n-1;++i)
		printf("%d\n",res[i]);
	return 0;
}