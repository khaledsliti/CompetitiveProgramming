// RedStone
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

int n, k;
string s;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> k;
  cin >> s;
  set<char> ex;
  while(k--) {
    char c; cin >> c;
    ex.insert(c);
  }
  ll ans = 0;
  s += '#';
  int cnt = 0;
  for(int i = 0; i < sz(s); i++) {
    if(ex.find(s[i]) == ex.end()) {
      ans += 1LL * cnt * (cnt + 1) / 2;
      cnt = 0;
    } else {
      cnt++;
    }
  }
  cout << ans << endl;
  return 0;
}
