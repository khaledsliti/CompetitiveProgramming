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

string s[8];

void solve() {
  for(int i = 0; i < 8; i++) {
    cin >> s[i];
  }
  for(int i = 1; i < 7; i++) {
    for(int j = 1; j < 7; j++) {
      vector<char> t {s[i][j], s[i - 1][j - 1], s[i - 1][j + 1], s[i + 1][j - 1], s[i + 1][j + 1]};
      bool ok = true;
      for(char c: t) {
        if(c != '#') {
          ok = false;
        }
      }
      if(ok) {
        cout << i + 1 << " " << j + 1 << endl;
        return;
      }
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
