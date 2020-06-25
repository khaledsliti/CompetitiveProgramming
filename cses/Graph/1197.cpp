// We only fail when we stop trying
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

const int N = 2500, M = 5000;
const ll Inf = 1e18;

int n, m;
ll dist[N];
vector<pair<int, int>> g[N];
int prv[N];

int main()
{
  cin >> n >> m;
  for(int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    g[--a].pb({--b, c});
  }
  for(int i = 0; i < n; i++)
    dist[i] = 0, prv[i] = -1;
  int x;
  for(int it = 0; it < n; it++) {
    x = -1;
    for(int i = 0; i < n; i++) {
      for(auto e : g[i]) {
        int j = e.first, c = e.second;
        if(dist[i] < Inf && dist[j] > dist[i] + c) {
          dist[j] = dist[i] + c;
          prv[j] = i;
          x = j;
        }
      }
    }
  } 
  if(x == -1) cout << "NO" << endl;
  else {
    for(int i = 0; i < n; i++)
      x = prv[x];
    vector<int> cycle;
    for(int cur = x;; cur = prv[cur]) {
      cycle.push_back(cur + 1);
      if(sz(cycle) > 1 && cycle.front() == cycle.back())
        break;
    }
    cout << "YES" << endl;
    reverse(all(cycle));
    for(int x : cycle)
      cout << x << " ";
    cout << endl;
  }
  
  return 0;
}
