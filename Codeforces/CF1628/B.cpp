#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;

const int N = 2e5 + 5;

int n;
string s[N];

bool isPalin(const string& s) {
  for(int i = 0; i < sz(s) / 2; i++) {
    if(s[i] != s[sz(s) - 1 - i]) {
      return false;
    }
  }
  return true;
}

void solve() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> s[i];
  }
  for(int i = 0; i < n; i++) {
    if(isPalin(s[i])) {
      cout << "YES" << endl;
      return;
    }
  }
  set<string> ex, ex2, ex3;
  for(int i = n - 1; i >= 0; i--) {
    {
      if(ex.find(s[i]) != ex.end()) {
        cout << "YES" << endl;
        return;
      }
      string t = s[i];
      reverse(all(t));
      ex.insert(t);
    }
    if(sz(s[i]) == 2) {
      if(ex3.find(s[i]) != ex3.end()) {
        cout << "YES" << endl;
        return;
      }
      string t = s[i];
      reverse(all(t));
      ex2.insert(t);
    } else {
      assert(sz(s[i]) == 3);
      string t = s[i].substr(0, 2);
      if(ex2.find(t) != ex2.end()) {
        cout << "YES" << endl;
        return;
      }
      t = s[i];
      reverse(all(t));
      t.pop_back();
      ex3.insert(t);
    }
  }
  cout << "NO" << endl;
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
