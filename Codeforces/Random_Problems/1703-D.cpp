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
  set<string> s;
  vector<string> a(n);
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    s.insert(a[i]);
  }
  for(int i = 0; i < n; i++) {
    bool ok = false;
    for(int j = 1; j < sz(a[i]); j++) {
      string x = a[i].substr(0, j);
      string y = a[i].substr(j);
      if(s.find(x) != s.end() && s.find(y) != s.end()) {
        ok = true;
        break;
      }
    }
    cout << ok;
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
