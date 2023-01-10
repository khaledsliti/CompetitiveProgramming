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

const int N = 1e5 + 5;

int n;
string s;
int sum, z, o;

void solve() {
  cin >> n >> s;
  sum = 0;
  z = o = 0;
  for(char c: s) {
    if(c == '0') z++;
    else o++;
  }
  int ans = 0;
  for(int i = 0; i < n; i++) {
    int cur = (s[i] - '0') ^ sum;
    if(cur == 0) z--;
    else o--;
    if(cur == 1 && z > 0) {
      sum ^= 1;
      ans++;
      swap(z, o);
    }
  }
  cout << ans << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int T;
  cin >> T;
  while(T--) {
    solve();
  }
  return 0;
}
