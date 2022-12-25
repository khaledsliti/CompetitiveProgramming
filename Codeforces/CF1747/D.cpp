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

int n, q;
int arr[N];
int pref[N];
int sum[N];
map<int, array<vector<int>, 2>> pos;
int nxt[N];

void solve() {
  cin >> n >> q;
  pos.clear();
  pos[0][0].push_back(0);
  for(int i = 1; i <= n; i++) {
    cin >> arr[i];
    sum[i] = (arr[i] != 0) + sum[i - 1];
    pref[i] = arr[i] ^ pref[i - 1];
    pos[pref[i]][i & 1].push_back(i);
  }
  auto getSum = [&](int l, int r) -> int {
    return sum[r] - (l > 0 ? sum[l - 1] : 0);
  };
  auto getXor = [&](int l, int r) -> int {
    return pref[r] ^ (l > 0 ? pref[l - 1] : 0);
  };
  while(q-- > 0) {
    int l, r;
    cin >> l >> r;
    int len = r - l + 1;
    if(getSum(l, r) == 0) {
      cout << 0 << endl;
      continue;
    }
    if(getXor(l, r) != 0) {
      cout << -1 << endl;
      continue;
    }
    if((len & 1) || !arr[l] || !arr[r]) {
      cout << 1 << endl;
      continue;
    }
    auto& tmp = pos[pref[l - 1]][l & 1];
    int idx = lower_bound(all(tmp), l) - begin(tmp);
    if(idx < sz(tmp) && tmp[idx] <= r) {
      cout << 2 << endl;
      continue;
    }
    cout << -1 << endl;
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int T = 1;
  while(T--) {
    solve();
  }
  return 0;
}
