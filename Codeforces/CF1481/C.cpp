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

int n, m;
int a[N], b[N], c[N], d[N], sol[N];
map<int, vector<int>> cnt;

void solve() {
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  map<int, int> pos;
  for(int i = 0; i < n; i++) {
    cin >> b[i];
    pos[b[i]] = i;
  }
  for(int i = 0; i < m; i++) {
    cin >> c[i];
    d[i] = 0;
    sol[i] = -1;
  }
  cnt.clear();
  for(int i = 0; i < n; i++) {
    if(a[i] != b[i]) {
      cnt[b[i]].pb(i);
    }
  }
  int idx = -1;
  bool imp = false;
  for(int i = m - 1; i >= 0; i--) {
    if(cnt[c[i]].size() > 0) {
      d[i] = 1;
      sol[i] = cnt[c[i]].back();
      cnt[c[i]].pop_back();
      idx = sol[i];
    } else if(pos.count(c[i])) {
      sol[i] = pos[c[i]];
      idx = sol[i];
    } else if(idx != -1) {
      sol[i] = idx;
    } else {
      imp = true;
    }
  }
  for(auto x: cnt) {
    if(x.second.size() > 0) {
      imp = true;
      break;
    }
  }
  if(imp) {
    cout << "NO" << endl;
    return;
  }
  cout << "YES" << endl;
  for(int i = 0; i < m; i++) {
    cout << sol[i] + 1 << " ";
  }
  cout << endl;
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
