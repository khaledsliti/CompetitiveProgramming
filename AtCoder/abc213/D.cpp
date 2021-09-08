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

const int N = 2e5 + 5;

int n;
vector<int> g[N];

void dfs(int u, int p) {
  cout << u + 1 << " ";
  for(int v: g[u]) {
    if(v != p) {
      dfs(v, u);
      cout << u + 1 << " ";
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
    --a, --b;
    g[a].pb(b);
    g[b].pb(a);
  }

  for(int i = 0; i < n; i++) {
    sort(all(g[i]));
  }

  dfs(0, -1);
  cout << endl;
  return 0;
}
