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

int n, k;
int x[N];
int dp[N];

void solve() {
  cin >> n >> k;
  for(int i = 0; i < n; i++) {
    cin >> x[i];
  }
  for(int i = 0, a; i < n; i++) {
    cin >> a;
  }
  sort(x, x + n);
  dp[n] = 0;
  for(int i = n - 1; i >= 0; i--) {
    dp[i] = lower_bound(x, x + n, x[i] + k + 1) - x - i;
    if(i + 1 < n) {
      dp[i] = max(dp[i], dp[i + 1]);
    }
  }
  int best = 0;
  for(int i = 0; i < n; i++) {
    int nxt = lower_bound(x, x + n, x[i] + k + 1) - x;
    int cnt = nxt - i;
    best = max(best, cnt + dp[nxt]);
  }
  cout << best << endl;
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
