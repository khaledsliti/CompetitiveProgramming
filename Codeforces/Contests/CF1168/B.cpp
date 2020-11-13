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

const int N = 3e5 + 5;

int n;
string s;

bool good(int i, int j) {
  for(int m = i + 1; m < j; m++) {
    for(int l = m - 1; l >= i; l--) {
      int r = 2 * m - l;
      if(r <= j && s[l] == s[m] && s[m] == s[r]) {
        return true;
      }
    }
  }
  return false;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> s;
  n = sz(s);

  ll ans = 0;

  for(int i = 0; i < n; i++) {
    for(int j = i + 2; j < n; j++) {
      if(good(i, j)) {
        ans += n - j;
        break;
      }
    }
  }

  cout << ans << endl;
  return 0;
}
