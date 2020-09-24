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

const int N = 3e5 + 5;

int n, q;
int a[N];
ll dp[N][2];
int vis[N][2];

ll solve(int idx, int t) {
  if(idx >= n) return 0;
  ll& r = dp[idx][t];
  if(vis[idx][t]) return r;
  vis[idx][t] = 1;
  r = solve(idx + 1, t);
  if(t == 0) {
    r = max(r, a[idx] - solve(idx + 1, !t));
  } else {
    r = min(r, a[idx] - solve(idx + 1, !t));
  }
  return r;
}

void update(int idx, int nw, ll& ans) {
  if(a[idx] < a[idx - 1]) {
    ans -= a[idx - 1] - a[idx];
  }
  if(nw < a[idx - 1]) {
    ans += a[idx - 1] - nw;
  }
  
  if(a[idx] > a[idx + 1]) {
    ans -= a[idx] - a[idx + 1];
  }
  if(nw > a[idx + 1]) {
    ans += nw - a[idx + 1];
  }

  a[idx] = nw;
}

void solve() {
  cin >> n >> q;
  for(int i = 0; i < n; i++) {
    cin >> a[i + 1];
  }
  a[0] = 0;
  a[n + 1] = 0;
  long long ans = 0;
  for(int i = 0; i <= n + 1; i++) {
    if(i > 0) {
      ans += max(0, a[i - 1] - a[i]);
    }
  }
  cout << max(ans, 1LL * n) << endl;

  for(int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;
    int x = a[l], y = a[r];
    update(l, y, ans);
    update(r, x, ans);
    cout << max(ans, 1LL * n) << endl;
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
