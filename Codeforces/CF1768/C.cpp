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
int a[N];
vector<int> pos[N];
vector<int> rem;
vector<int> col[N];
int ans[2][N];

void solve() {
  cin >> n;
  rem.clear();
  for (int i = 1; i <= n; i++) {
    pos[i].clear();
    col[i].clear();
  }
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    pos[a[i]].push_back(i);
  }
  for (int i = 1; i <= n; i++) {
    if (sz(pos[i]) > 2) {
      cout << "NO" << endl;
      return;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (sz(pos[i]) == 0) {
      rem.push_back(i);
      rem.push_back(i);
      continue;
    }
    if (sz(pos[i]) == 1) {
      col[i].push_back(pos[i][0]);
      col[i].push_back(pos[i][0]);
      continue;
    }
    if (sz(rem) <= 1) {
      cout << "NO" << endl;
      return;
    }
    for (int it = 0; it < 2; it++) {
      int other = rem.back();
      rem.pop_back();
      col[other].push_back(pos[i][it]);
      col[i].push_back(pos[i][it]);
    }
  }
  if (sz(rem) != 0) {
    cout << "NO" << endl;
    return;
  }
  cout << "YES" << endl;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 2; j++) {
      ans[j][i] = -1;
    }
  }
  for (int i = 1; i <= n; i++) {
    int x = col[i][0], y = col[i][1];
    if (ans[0][x] == -1) {
      ans[0][x] = i;
      ans[1][y] = i;
    } else {
      ans[0][y] = i;
      ans[1][x] = i;
    }
  }
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < n; j++) {
      cout << ans[i][j] << " ";
    }
    cout << endl;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int T;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
