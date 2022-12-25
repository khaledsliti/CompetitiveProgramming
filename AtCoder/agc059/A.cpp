// RedStone
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;

const int N = 1e5 + 5;

int n, q;
string s;
vector<pair<int, int>> qr[N];
int bit[N];
int ans[N];

int get(int x) {
  int r = 0;
  for (int i = x + 1; i > 0; i -= i & -i) {
    r += bit[i];
  }
  return r;
}

int get(int l, int r) { return get(r) - get(l - 1); }

void add(int x, int v) {
  for (int i = x + 1; i < N; i += i & -i) {
    bit[i] += v;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> q;
  cin >> s;
  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;
    --l, --r;
    qr[l].push_back({r, i});
  }

  for (int i = 0; i < q; i++) {
    ans[i] = 1e9;
  }

  for(int target = 0; target < 3; target++) {
    // cout << char(target + 'A') << ": " << endl;
    memset(bit, 0, sizeof bit);
    set<char> so_far;
    int last_idx = -1, last_val;
    for(int i = n - 1; i >= 0; i--) {
      if (s[i] - 'A' != target) {
        so_far.insert(s[i]);
        if (last_idx != -1) {
          add(last_idx, -last_val);
        }
        add(i, sz(so_far));
        last_idx = i;
        last_val = sz(so_far);
      } else {
        so_far.clear();
        last_idx = -1;
      }

      // for(int j = 0; j < n; j++) {
      //   cout << get(j, j) << " ";
      // }
      // cout << endl;

      for(auto qq : qr[i]) {
        int r = qq.first;
        int idx = qq.second;
        ans[idx] = min(ans[idx], get(i, r));
      }
    }
  }

  for (int i = 0; i < q; i++) {
    cout << ans[i] << endl;
  }
  return 0;
}
