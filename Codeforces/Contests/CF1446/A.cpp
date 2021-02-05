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

const int N = 2e5 + 5;

int n;
ll W;

void solve() {
  cin >> n >> W;
  vector<ll> w;
  for(int i = 0; i < n; i++) {
    ll x;
    cin >> x;
    w.pb(x);
  }
  for(int i = 0; i < sz(w); i++) {
    if(2 * w[i] >= W && w[i] <= W) {
      cout << 1 << endl;
      cout << i + 1 << endl;
      return;
    }
  }
  vector<int> sol;
  ll s = 0;
  for(int i = 0; i < sz(w); i++) {
    if(w[i] > W) continue;
    s += w[i];
    sol.push_back(i + 1);
    if(2 * s >= W) {
      break;
    }
  }
  if(s <= W && 2 * s >= W) {
    cout << sz(sol) << endl;
    for(int x: sol) {
      cout << x << " ";
    }
    cout << endl;
  } else {
    cout << -1 << endl;
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
