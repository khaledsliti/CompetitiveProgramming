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

const int N = 5e5 + 5;

int n;
string s;
long long dp[N];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> s;
  n = sz(s);
  for (int i = n - 1; i >= 0; i--) {
    vector<int> fr(10, 0);
    fr[s[i] - '0']++;
    int odd = 1;
    int j = i + 1;
    while (j < n && odd > 0) {
      int d = s[j] - '0';
      fr[d] ^= 1;
      if (!fr[d]) {
        odd--;
      } else {
        odd++;
      }
      j++;
    }
    if (odd) {
      continue;
    }
    dp[i] = 1 + dp[j];
  }

  long long ans = 0;
  for (int i = 0; i < n; i++) {
    ans += dp[i];
  }
  cout << ans << endl;
  return 0;
}
