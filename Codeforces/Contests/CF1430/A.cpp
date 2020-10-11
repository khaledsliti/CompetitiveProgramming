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
  for(int i = 0; i * 7 <= n; i++) {
    for(int j = 0; j * 5 <= n - i * 7; j++) {
      int rem = n - i * 7 - j * 5;
      if(rem % 3 == 0) {
        cout << rem / 3 << " " << j << " " << i << endl;
        return;
      }
    }
  }
  cout << -1 << endl;
}

int main()
{
  int T;
  cin >> T;
  while(T--) {
    solve();
  }
  return 0;
}
