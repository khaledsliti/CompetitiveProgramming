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

int n;
string s, p;

void solve() {
  cin >> n >> s; p = s;
  sort(all(p));
  string t;
  vector<int> pos;
  for(int i = 0; i < sz(s); i++) {
    if(s[i] != p[i]) {
      pos.push_back(i);
    }
  }
  if(sz(pos)) {
    cout << 1 << endl;
    cout << sz(pos);
    for(int c: pos) {
      cout << " " << c + 1;
    }
    cout << endl;
  } else {
    cout << 0 << endl;
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
