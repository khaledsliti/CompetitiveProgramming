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
vector<pair<int, int>> edges;
int deg[N], par[N];
int best[N];

int fs(int x) {
  return par[x] == x ? x : par[x] = fs(par[x]);
}

bool check(int d, int* cur_deg) {
  int cnt = n;
  for(int i = 0; i < n; i++) {
    par[i] = i;
    cur_deg[i] = 0;
  }
  for(int i = 0; i < m; i++) {
    int a = edges[i].first, b = edges[i].second;
    int par_a = fs(a), par_b = fs(b);
    if(par_a != par_b && cur_deg[a] < d && cur_deg[b] < d) {
      par[par_a] = par_b;
      cnt--;
      cur_deg[a]++, cur_deg[b]++;
    }
  }
  if(cnt > 1) return false;
  for(int i = 1; i < n; i++) {
    if(cur_deg[i] != best[i]) {
      return false;
    }
  }
  return true;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m;
  for(int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    --x, --y;
    if(x > y) swap(x, y);
    edges.push_back({x, y});
  }
  sort(all(edges), [](const pair<int, int>& a, const pair<int, int>& b) {
    if(a.second != b.second) return a.second < b.second;
    return a.first < b.first;
  });

  check(n, best);

  int l = 0, r = n, ans = -1;
  while(l <= r) {
    int mid = (l + r) >> 1;
    if(check(mid, deg)) {
      ans = mid;
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  cout << ans << endl;
  return 0;
}