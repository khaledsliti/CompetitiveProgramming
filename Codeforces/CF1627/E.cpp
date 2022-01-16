#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;

const int N = 2e5 + 5;
const ll INF = 1e18;

struct Ladder {
  ll cur_i, cur_j, nxt_i, nxt_j, h;
};

int n, m, k;
ll x[N];
vector<int> out[N];
map<pair<int, int>, vector<Ladder>> lad;
vector<vector<ll>> dp;
vector<vector<int>> vis;
int cur_idx;
map<pair<int, int>, int> idx;
bool done;

int getRight(int i, int j) {
  int jj = upper_bound(all(out[i]), j) - begin(out[i]);
  if(jj >= sz(out[i])) return -1;
  return out[i][jj];
}

int getLeft(int i, int j) {
  int jj = lower_bound(all(out[i]), j) - begin(out[i]);
  if(jj == 0) return -1;
  return out[i][jj - 1];
}

ll solve(int i, int j, int dir) {
  if(i == n - 1 && j == m - 1) {
    done = true;
    return 0;
  }
  assert(idx.count({i, j}) > 0);
  int index = idx[{i, j}];
  ll& r = dp[index][dir + 1];
  if(vis[index][dir + 1]) return r;
  vis[index][dir + 1] = 1;
  r = INF;
  // up
  for(const Ladder& ladder: lad[{i, j}]) {
    ll cur = -ladder.h + solve(ladder.nxt_i, ladder.nxt_j, 0);
    r = min(r, cur);
  }
  if(dir >= 0) { // move right 
    int new_j = getRight(i, j);
    if(new_j != -1) {
      assert(new_j >= j);
      r = min(r, 1LL * x[i] * (new_j - j) + solve(i, new_j, 1));
    }
  }
  if(dir <= 0) { // move left
    int new_j = getLeft(i, j);
    if(new_j != -1) {
      assert(new_j <= j);
      r = min(r, 1LL * x[i] * (j - new_j) + solve(i, new_j, -1));
    }
  }
  return r;
}



void solve() {
  cin >> n >> m >> k;
  for(int i = 0; i < n; i++) {
    cin >> x[i];
  }
  lad.clear();
  for(int i = 0; i < n; i++) {
    out[i].clear();
  }
  idx.clear();
  for(int i = 0; i < k; i++) {
    int a, b, c, d, h;
    cin >> a >> b >> c >> d >> h;
    --a, --b, --c, --d;
    out[a].push_back(b);
    lad[{a, b}].push_back({a, b, c, d, h});
    idx[{a, b}]; idx[{c, d}];
  }
  out[n - 1].push_back(m - 1);
  for(int i = 0; i < n; i++) {
    sort(all(out[i]));
    out[i].resize(unique(all(out[i])) - begin(out[i]));
  }

  idx[{0, 0}]; idx[{n - 1, m - 1}];
  cur_idx = 0;
  for(auto& x: idx) {
    x.second = cur_idx++;
  }

  dp.clear();
  dp.resize(cur_idx + 5, vector<ll>(3, -1));
  vis.clear();
  vis.resize(cur_idx + 5, vector<int>(3, 0));

  done = false;
  ll ans = solve(0, 0, 0);
  if(!done) {
    cout << "NO ESCAPE" << endl;
  } else {
    cout << ans << endl;
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int T;
  cin >> T;
  while(T--) {
    solve();
  }
  return 0;
}
