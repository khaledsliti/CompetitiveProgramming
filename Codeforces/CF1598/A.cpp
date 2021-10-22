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
  int n;
  cin >> n;
  string s[2];
  for(int i = 0; i < 2; i++) {
    cin >> s[i];
  }
  for(int j = 1; j < n; j++) {
    if(s[0][j] == '1' && s[1][j] == '1') {
      cout << "NO" << endl;
      return;
    }
  }
  cout << "YES" << endl;
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
