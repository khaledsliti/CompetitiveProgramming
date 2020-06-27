// We only fail when we stop trying
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

string s;

void solve() {
  cin >> s;
  map<int, int> first;
  int cur = 0;
  for(int i = 0; i < sz(s); i++) {
    if(s[i] == '+') cur++;
    else cur--;
    if(!first.count(cur)) {
      first[cur] = i + 1;
    }
  }
  ll ans = 0;
  for(int i = 1; i <= sz(s) + 5; i++) {
    if(!first.count(-i)) {
      ans += sz(s);
      break;
    }
    ans += first[-i];
  }
  cout << ans << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--)
    solve();
  return 0;
}
