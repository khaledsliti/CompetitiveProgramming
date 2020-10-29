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

const int N = 1e5 + 5;

void solve() {
  int n; cin >> n;
  string s; cin >> s;
  int ans = 0;
  for(int i = 1; i < n; i++) {
    ans += s[i - 1] == s[i];
  }
  cout << (ans + 1) / 2 << endl;
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
