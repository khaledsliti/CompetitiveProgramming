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

  string s; cin >> s;
  int k; cin >> k;
  int l = 0;
  int have = 0;
  int ans = 0;
  for(int i = 0; i < sz(s); i++) {
    have += s[i] == '.';
    while(have > k) {
      have -= s[l++] == '.';
    }
    ans = max(ans, i - l + 1);
  }
  cout << ans << endl;
  return 0;
}
