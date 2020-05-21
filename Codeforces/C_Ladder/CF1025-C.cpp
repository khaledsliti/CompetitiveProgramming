// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 2e5 + 5;

string s;
int dp[N];

int main()
{
  cin >> s;
  s += s;
  int ans = 1;
  int cur = 0;
  for(int i = 1 ; i < sz(s) ; i++) {
    if(s[i] != s[i - 1])
      cur++;
    else cur = 1;
    ans = max(ans, min(cur, sz(s) / 2));
  }
  cout << ans << endl;
  return 0;
}
