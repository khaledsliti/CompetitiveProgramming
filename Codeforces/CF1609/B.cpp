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

int n, q;
string s;
int ans = 0;

bool good(int idx) {
  return s.substr(idx, 3) == "abc";
}

int get(int idx) {
  int r = 0;
  for(int i = max(0, idx - 2); i <= idx; i++) {
    r += good(i);
  }
  return r;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> q;
  cin >> s;
  for(int i = 0; i + 3 <= n; i++) {
    ans += good(i);
  }

  while(q--) {
    int idx; char c;
    cin >> idx >> c; --idx;
    ans -= get(idx);
    s[idx] = c;
    ans += get(idx);
    cout << ans << endl;
  }
  return 0;
}
