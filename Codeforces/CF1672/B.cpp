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
  string s; cin >> s;
  int a = 0, b = 0;
  for(int i = 0; i < sz(s); i++) {
    a += s[i] == 'A';
    b += s[i] == 'B';
    if (b > a) {
      cout << "No" << endl;
      return;
    }
  }
  if(s.front() == 'B' || s.back() == 'A' || b == 0 || a < b) {
    cout << "No" << endl;
    return;
  }
  cout << "Yes" << endl;
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
