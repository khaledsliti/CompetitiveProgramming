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

const int N = 1e5 + 5;

int n;
char s[N];

void solve() {
  cin >> n;
  if(n <= 26) {
    for(int i = 0; i < n; i++) {
      s[i] = char('a' + i);
    }
  } else {
    s[0] = s[2] = s[3] = 'a';
    s[1] = 'b';
    for(int i = 4; i < n; i += 6) {
      if(i + 6 <= n) {
        s[i] = s[i + 3] = 'b';
        s[i + 1] = s[i + 2] = s[i + 4] = s[i + 5] = 'a';
      } else {
        for(int j = 0; i < n; i++, j++) {
          s[i] = char('c' + j);
        }
      }
    }
  }
  for(int i = 0; i < n; i++) {
    cout << s[i];
  }
  cout << endl;
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
