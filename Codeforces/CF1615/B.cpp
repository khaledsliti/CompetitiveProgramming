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

const int N = 2e5 + 1;
const int L = 30;

int cnt[L][N];

int get(int i, int l, int r) {
  return cnt[i][r] - cnt[i][l - 1];
}

void solve() {
  int l, r; cin >> l >> r;
  int ans = r;
  for(int i = 0; i < L; i++) {
    ans = min(ans, r - l + 1 - get(i, l, r));
  }
  cout << ans << endl;
}

void pre() {
  for(int i = 0; i < L; i++) {
    for(int j = 1; j < N; j++) {
      cnt[i][j] = cnt[i][j - 1];
      if(j & (1 << i)) {
        cnt[i][j]++;
      }
    }
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  pre();

  int T;
  cin >> T;
  while(T--) {
    solve();
  }
  return 0;
}
