#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
typedef long long ll;
const int mod = 1e9 + 7;
const int N = 51;

int p[N];
int fs(int x)
{
  return p[x] == x ? x : p[x] = fs(p[x]);
}

int solve(vector<int>& v)
{
  int n = sz(v);
  vector<vector<int>> g(n, vector<int>(N));
  g[n - 1][0] = 0;
  for(int i = n - 1 ; i >= 0 ; i--){
    for(int j = 0 ; j < N ; j++)
      p[j] = j;
    for(int j = 1 ; j <= v[i] ; j++){
      int cur = g[i][j - 1];
      int nxt = fs(cur);
      if(nxt == cur)
        p[cur] = cur + 1;
      g[i][j] = fs(0);
    }
    if(i >= 1)
      g[i - 1][0] = g[i][v[i]];
  }
  return g[0][v[0]];
}

int main()
{
  int T;
  cin >> T;
  while(T--){
    int n, m;
    cin >> n >> m;
    int res = 0;
    for(int i = 0 ; i < n ; i++){
      vector<int> v;
      for(int j = 0 ; j < m ; j++){
        int a; cin >> a;
        v.pb(a);
      }
      res ^= solve(v);
    }
    if(res) cout << "FIRST" << endl;
    else cout << "SECOND" << endl;
  }
  return 0;
}
