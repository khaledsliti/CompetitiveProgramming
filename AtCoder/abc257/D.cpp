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

const int N = 1e5 + 5;

int n;
ll x[N], y[N], p[N];

bool check(ll s) {
  vector<vector<int>> g(n);
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(i == j) continue;
      if(p[i] * s >= abs(x[i] - x[j]) + abs(y[i] - y[j])) {
        g[i].push_back(j);
      }
    }
  }

  for(int i = 0; i < n; i++) {
    queue<int> q;
    q.push(i);
    vector<int> vis(n, 0);
    vis[i] = 1;
    int cnt = 0;
    while(!q.empty()) {
      int u = q.front();
      q.pop();
      cnt++;
      for(int v: g[u]) {
        if(!vis[v]) {
          q.push(v);
          vis[v] = 1;
        }
      }
    }
    if(cnt == n) {
      return true;
    }
  }
  return false;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> x[i] >> y[i] >> p[i];
  }

  ll low = 1, high = 4e9 + 5, ans = 1;
  while(low <= high) {
    ll mid = (low + high) / 2;
    if(check(mid)) {
      ans = mid;
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  cout << ans << endl;
  return 0;
}
