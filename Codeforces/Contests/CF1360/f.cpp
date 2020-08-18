// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
typedef long long ll;

const int N = 11;

int n, m;
string s[N];

int dist(string& a, string& b) {
  int res = 0;
  for(int i = 0; i < sz(a); i++)
    res += a[i] != b[i];
  return res;
}

bool check(string cur) {
  for(int i = 0; i < n; i++)
    if(dist(cur, s[i]) > 1)
      return false;
  return true;
}

int main()
{
  int T;
  cin >> T;
  while(T--) {
    cin >> n >> m;
    for(int i = 0; i < n; i++)
      cin >> s[i];
    bool done = false;
    for(int i = 0; i < n && !done; i++) {
      for(int j = 0; j < m && !done; j++) {
        for(int c = 0; c < 26 && !done; c++) {
          string cur = s[i];
          cur[j] = char('a' + c);
          if(check(cur)) {
            cout << cur << endl;
            done = true;
          }
        }
      }
    }
    if(!done) cout << -1 << endl;
  }
  return 0;
}
