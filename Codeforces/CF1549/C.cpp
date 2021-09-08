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
int ans;
set<int> g[N];
int good[N];

void add(int u, int v) {
  g[u].insert(v);
  g[v].insert(u);
  for(int node: {u, v}) {
    if(good[node]) {
      if(*g[node].rbegin() > node) {
        good[node] = 0;
        ans--;
      }
    }
  }
  // for(int i = 0; i < n; i++) {
  //   cout << good[i] << " ";
  // }
  // cout << endl;
}

void del(int u, int v) {
  g[u].erase(v);
  g[v].erase(u);
  for(int node: {u, v}) {
    if(!good[node]) {
      if(!g[node].size() || *g[node].rbegin() < node) {
        good[node] = 1;
        ans++;
      }
    }
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int m;
  cin >> n >> m;
  ans = n;
  for(int i = 0; i < n; i++) {
    good[i] = 1;
  }

  while(m--) {
    int u, v;
    cin >> u >> v;
    add(--u, --v);
    // cout << ans << endl;
  }

  // return 0;

  int q;
  cin >> q;
  while(q--) {
    int t; cin >> t;
    if(t == 1) {
      int u, v;
      cin >> u >> v;
      add(--u, --v);
    } else if(t == 2) {
      int u, v;
      cin >> u >> v;
      del(--u, --v);
    } else {
      cout << ans << endl;
    }
  }

  return 0;
}
