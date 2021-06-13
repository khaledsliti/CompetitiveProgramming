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

void solve() {
  string a, b;
  cin >> a >> b;
  reverse(all(a));
  while(sz(a) < sz(b)) a += '0';
  reverse(all(a));
  long long last = 0;
  long long ans = 0;
  for(int i = 0; i < sz(b); i++) {
    long long cur = 0;
    int x = a[i] - '0';
    int y = b[i] - '0';
    if(last > 0) {
      cur += (last - 1) * 10;
      cur += 10 - x + y;
    } else {
      cur += y - x;
    }
    last = cur;
    ans += cur;
  }
  cout << ans << endl;
}

int main()
{
  int T;
  scanf("%d", &T);
  while(T--) {
    solve();
  }
  return 0;
}
