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

const int N = 9;

int n;
int c[N + 1];

int main()
{
  cin >> n;
  for(int i = 1; i <= N; i++) {
    cin >> c[i];
  }
  int mx = 1e9, d;
  for(int i = N; i >= 1; i--) {
    if(c[i] < mx) {
      mx = c[i];
      d = i;
    }
  }
  string ans;
  while(n >= mx) {
    n -= mx;
    ans += char('0' + d);
  }
  for(int i = 0; i < sz(ans); i++) {
    for(int cur = 9; cur > d; cur--) {
      int diff = c[cur] - c[d];
      if(n >= diff) {
        n -= diff;
        ans[i] = char('0' + cur);
        break;
      }
    }
  }

  cout << ans << endl;
  return 0;
}
