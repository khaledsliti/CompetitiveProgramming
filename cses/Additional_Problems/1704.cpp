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

const int N = 1e5 + 5;

int n;
vector<int> g[N];
int d[N];
vector<int> vt;

void dfs(int u, int p) {
  if(d[u] == 1) vt.pb(u);
  for(int v: g[u]) {
    if(v != p) {
      dfs(v, u);
    }
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  for(int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    g[--a].pb(--b);
    g[b].pb(a);
    d[a]++;
    d[b]++;
  }
  dfs(0, -1);
  int s = sz(vt) / 2;
  cout << (sz(vt) + 1) / 2 << endl;
  for(int i = 0; i < s; i++) {
    cout << vt[i] + 1 << " " << vt[i + s] + 1 << endl;
  }
  if(sz(vt) & 1) {
    cout << vt[0] + 1 << " " << vt.back() + 1 << endl;
  }
  return 0;
}
