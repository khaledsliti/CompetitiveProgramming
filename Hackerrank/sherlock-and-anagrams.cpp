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

int main()
{
  int T;
  cin >> T;
  while(T--) {
    string s;
    cin >> s;
    unordered_map<string, int> mp;
    for(int i = 0; i < sz(s); i++) {
      string tmp;
      for(int j = i; j < sz(s); j++) {
        tmp += s[j];
        sort(all(tmp));
        mp[tmp]++;
      }
    }
    int ans = 0;
    for(auto x : mp)
      ans += x.second * (x.second - 1) / 2;
    cout << ans << endl;
  }
  return 0;
}
