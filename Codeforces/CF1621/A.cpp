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
  int n, m, k;
  cin >> n >> k;
  m = n;
  vector<vector<char>> sol(n, vector<char>(m, '.'));
  for(int i = 0; i < min(n, m) && k > 0; i += 2) {
    sol[i][i] = 'R';
    k--;
  }
  if(k > 0) {
    cout << -1 << endl;
  } else {
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        cout << sol[i][j];
      }
      cout << endl;
    }
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
