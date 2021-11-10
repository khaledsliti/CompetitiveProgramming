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



int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int T;
  cin >> T;
  while(T--) {
    string s; cin >> s;
    int idx[26];
    for(int i = 0; i < sz(s); i++) {
      idx[s[i] - 'a'] = i;
    }
    cin >> s;
    int ans = 0;
    for(int i = 1; i < sz(s); i++) {
      ans += abs(idx[s[i] - 'a'] - idx[s[i - 1] - 'a']);
    }
    cout << ans << endl;
  }
  return 0;
}
