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

const int N = 250;

int n, k;
string s;
char a, b;
ll dp[N][N][N];

ll solve(int i, int cnt, int rem) {
  if(i >= n) {
    return 0;
  }
  ll& res = dp[i][cnt][rem];
  if(res != -1) return res;
  res = 0;
  for(int cur = 0; cur < 26; cur++) {
    if(rem == 0 && cur != s[i] - 'a')
      continue;
    res = max(res, (cur == b - 'a' ? cnt : 0) + solve(i + 1, cnt + (cur == a - 'a'), rem - (cur != s[i] - 'a')));
  }
  return res;
}

int main()
{
  cin >> n >> k;
  cin >> s >> a >> b;
  memset(dp, -1, sizeof dp);
  cout << solve(0, 0, k) << endl;
  return 0;
}
