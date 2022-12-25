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

int n, l, r;

void solve() {
  cin >> n >> l >> r;
  auto get = [&](int x) {
    int y = l / x * x;
    if(y < l) y += x;
    return y <= r ? y : -1;
  };
  vector<int> sol;
  for(int i = 1; i <= n; i++) {
    int t = get(i);
    if(t == -1) {
      cout << "NO" << endl;
      return;
    }
    sol.pb(t);
  }
  cout << "YES" << endl;
  for(int x: sol) cout << x << " ";
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
