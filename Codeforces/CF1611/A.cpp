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
  string s;
  cin >> s;
  auto even = [](char c) { return (c  - '0') % 2 == 0; };
  if(even(s.back())) cout << 0 << endl;
  else if(even(s[0])) cout << 1 << endl;
  else {
    for(char c: s) {
      if(even(c)) {
        cout << 2 << endl;
        return;
      }
    }
    cout << -1 << endl;
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
