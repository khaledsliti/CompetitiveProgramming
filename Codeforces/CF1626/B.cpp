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
  for(int i = sz(s) - 2; i >= 0; i--) {
    int a = s[i] - '0';
    int b = s[i + 1] - '0';
    int d = a + b;
    if(d >= 10) {
      cout << s.substr(0, i) << d << s.substr(i + 2) << endl;
      return;
    }
  }
  reverse(all(s));
  int a = s.back() - '0'; s.pop_back();
  int b = s.back() - '0'; s.pop_back();
  reverse(all(s));
  cout << a + b << s << endl;
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
