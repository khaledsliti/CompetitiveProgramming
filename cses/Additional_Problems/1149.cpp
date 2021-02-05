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

  string s;
  cin >> s;

  int cnt[26], mod = 1e9 + 7;
  memset(cnt, 0, sizeof cnt);

  for(int i = sz(s) - 1; i >= 0; i--) {
    int cur = s[i] - 'a';
    for(int j = 0; j < 26; j++) {
      if(j == cur) cnt[cur]++;
      else cnt[cur] += cnt[j];
      cnt[cur] %= mod;
    }
  }

  int ans = 0;
  for(int i = 0; i < 26; i++) {
    ans = (ans + cnt[i]) % mod;
  }

  cout << ans << endl;
  return 0;
}
