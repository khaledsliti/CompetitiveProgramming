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



void solve() {
  int n; cin >> n;
  vector<int> a(n);
  int g = 0;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    g = __gcd(g, a[i]);
  }
  if (g == 1) {
    cout << 0 << endl;
    return;
  }

  for(int i = n - 1; i >= n - 2; i--) {
    int g = 0;
    for(int j = 0; j < n; j++) {
      if(i != j) {
        g = __gcd(g, a[j]);
      }
    }
    if(__gcd(g, __gcd(a[i], i + 1)) == 1) {
      cout << n - i << endl;
      return;
    }
  }

  cout << 3 << endl;
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
