// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 105;

int n, m;

void solve() {
  cin >> n >> m;
  for(int i = 0 ; i < n ; i++) {
    for(int j = 0 ; j < m ; j++) {
      if(!i && !j) cout << 'W';
      else cout << 'B';
    }
    cout << endl;
  }
}

int main()
{
  int t;
  cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}
