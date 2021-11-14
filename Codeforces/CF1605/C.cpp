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

int n;
string s;

void solve() {
  cin >> n >> s;
  for(int len = 2; len <= 8; len++) {
    int fr[3] {0, 0, 0};
    for(int i = 0; i < n; i++) {
      fr[s[i] - 'a']++;
      if(i - len >= 0) {
        fr[s[i - len] - 'a']--;
      }
      if(i >= len - 1 && fr[0] > max(fr[1], fr[2])) {
        cout << len << endl;
        return;
      }
    }
  }
  cout << -1 << endl;
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
