#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 1e5 + 5;

int n, root;
int c[N];
vector<int> g[N];

int main()
{
  scanf("%d", &n);
  for(int i = 0 ; i < n ; i++){
    int p;
    scanf("%d%d", &p, &c[i]);
    if(p != -1)
      g[--p].pb(i);
    else
      root = i;
  }
  vector<int> ans;
  queue<int> q;
  q.push(root);
  while(!q.empty()){
    int u = q.front();
    q.pop();
    for(int i = 0 ; i < sz(g[u]) ; i++){
      c[u] &= c[g[u][i]];
      q.push(g[u][i]);
    }
    if(c[u])
      ans.push_back(u);
  }
  sort(all(ans));
  if(sz(ans))
    for(int i = 0 ; i < sz(ans) ; i++)
      cout << ans[i] + 1 << " ";
  else
    cout << -1;
  return 0;
}
