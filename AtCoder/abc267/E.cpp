// RedStone
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

int n, m;
int arr[N];
long long cost[N];
vector<int> g[N];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  set<pair<int, int>> done;
  while(m--) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    if(done.find({u, v}) != done.end()) continue;
    cost[u] += arr[v];
    cost[v] += arr[u];
    g[u].push_back(v);
    g[v].push_back(u);
    done.insert({u, v});
    done.insert({v, u});
  }

  set<pair<long long, pair<int, int>>> s;
  for(int i = 0; i < n; i++) {
    s.insert({cost[i], {-arr[i], i}});
  }

  vector<bool> del(n, false);
  long long ans = -1;
  for(int i = 0; i < n; i++) {
    int mn = s.begin()->second.second;
    s.erase(s.begin());
    del[mn] = true;
    for(int x: g[mn]) {
      if(del[x]) continue;
      s.erase({cost[x], {-arr[x], x}});
      cost[x] -= arr[mn];
      s.insert({cost[x], {-arr[x], x}});
    }
    ans = max(ans, cost[mn]);
  }
  cout << ans << endl;
  return 0;
}
