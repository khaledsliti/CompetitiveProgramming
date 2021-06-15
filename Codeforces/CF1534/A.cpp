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

const int N = 51;

int n, m;
string s[N];

void solve() {
  cin >> n >> m;
  int r = -1, w = -1;
  bool ok = true;
  for(int i = 0; i < n; i++) {
    cin >> s[i];
    for(int j = 0; j < m; j++) {
      int idx = (i + j) & 1;
      if(s[i][j] == 'R') {
        if(r == -1) r = idx;
        else if(r != idx) ok = false;
      } else if(s[i][j] == 'W') {
        if(w == -1) w = idx;
        else if(w != idx) ok = false;
      }
    }
  }
  if(!ok) cout << "NO" << endl;
  else {
    if(r == -1 && w == -1) r = 0, w = 1;
    else if(r == -1 && w != -1) r = !w;
    else if(r != -1 && w == -1) w = !r;
    else if(r == w) {
      cout << "NO" << endl;
      return;
    }
    cout << "YES" << endl;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        int idx = (i + j) & 1;
        if(idx == r) s[i][j] = 'R';
        else s[i][j] = 'W';
      }
      cout << s[i] << endl;
    }
  }
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
