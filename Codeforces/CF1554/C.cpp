// Guess Who's Back
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

int solve(int n, int m) {
  set<int> ex;
  for(int i = 0; i <= m; i++) {
    ex.insert(i ^ n);
  }
  for(int i = 0; i <= 2 * m; i++) {
    if(ex.count(i) == 0) {
      return i;
    }
  }
  return -1;
}

void solve() {
  ll n, m;
  cin >> n >> m;
  ll ans = 1e18;
  if(n == 0) {
    ans = m + 1;
  } else if(m < n) {
    ans = 0;
  } else {
    int b = 0;
    while((1LL << b) <= m) {
      b++;
    }
    ll x = 0;
    while(b >= 0) {
      int i = (m >> b) & 1;
      int j = (n >> b) & 1;
      if(i && !j) {
        x |= (1LL << b);
      } else if(!i && j) {
        break;
      } else if(!i && !j) {
        ans = min(ans, x ^ (1LL << b));
      }
      b--;
    }
    if((n ^ x) > m) {
      ans = min(ans, x);
    }
  }
  cout << ans << endl;
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
