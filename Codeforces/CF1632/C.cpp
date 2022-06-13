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
  int a, b;
  cin >> a >> b;
  int ans = b - a;
  for(int i = a; i <= b; i++) {
    int cur = i - a;
    if(i != b) {
      int output_second = i | b;
      cur += 1;
      cur += output_second - b;
    }
    ans = min(ans, cur);
  }
  for(int i = b; i <= 2 * b; i++) {
    int cur = i - b;
    if((a | i) == i) {
      ans = min(ans, 1 + cur);
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
/*
  1101110101100110
101000001001000110
*/