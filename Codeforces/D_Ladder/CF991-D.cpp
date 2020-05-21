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

const int N = 101;
const int Inf = 1e9;

int n;
int arr[N];
int dp[N][4];

int solve(int i, int last) {
  if(i >= n) return last == 0 ? 0 : -Inf;
  int& r = dp[i][last];
  if(r != -1) return r;
  if(arr[i] & last) return r = -Inf;
  int cur = arr[i] | last;
  r = solve(i + 1, 0);
  if(!(cur & 1) && !(cur & 2)) {
    r = max(r, 1 + solve(i + 1, 1));
    r = max(r, 1 + solve(i + 1, 2));
  }
  if(!(cur & 1)) {
    r = max(r, 1 + solve(i + 1, 3));
  }
  if(!(cur & 2)) {
    r = max(r, 1 + solve(i + 1, 3));
  }
  return r;
}

int main()
{
  for(int it = 0; it < 2; it++) {
    string s;
    cin >> s;
    n = sz(s);
    for(int i = 0; i < n; i++)
      if(s[i] == 'X')
        arr[i] |= (1 << it);
  }
  memset(dp, -1, sizeof dp);
  int ans = solve(0, 0);
  cout << ans << endl;
  return 0;
}
