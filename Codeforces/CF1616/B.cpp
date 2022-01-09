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

void print(string p) {
  cout << p;
  reverse(all(p));
  cout << p << endl;
}

void solve() {
  int n; cin >> n;
  string s; cin >> s;
  string p = s;
  sort(all(p));
  if(s == p) {
    print(s.substr(0, 1));
    return;
  }
  for(int i = 0; i < n - 1; i++) {
    if(s[i] <= s[i + 1]) {
      if(i == 0) {
        print(s.substr(0, 1));
        return;
      }
      while(i + 1 < n && s[i + 1] <= s[i]) {
        i++;
      }
      print(s.substr(0, i + 1));
      return;
    }
  }
  print(s);
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
