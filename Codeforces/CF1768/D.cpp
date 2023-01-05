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
int id[N], cur_id;
int out[N];

void solve() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    --a;
    out[i] = a;
  }
  for (int i = 0; i < n; i++) {
    id[i] = 0;
  }
  cur_id = 1;
  int curr = 0;
  for (int i = 0; i < n; i++) {
    if (id[i] == 0) {
      int x = i;
      int len = 0;
      while (id[x] == 0) {
        id[x] = cur_id;
        x = out[x];
        len++;
      }
      cur_id++;
      curr += len - 1;
    }
  }
  int ans = INT_MAX;
  for (int i = 0; i < n - 1; i++) {
    if (id[i] == id[i + 1]) {
      ans = min(ans, curr - 1);
    } else {
      ans = min(ans, curr + 1);
    }
  }
  cout << ans << endl;
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
