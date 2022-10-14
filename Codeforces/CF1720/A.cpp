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
  long long a, b, c, d;
  cin >> a >> b >> c >> d;
  a *= d;
  b *= c;
  if (a == b) cout << 0 << endl;
  else if(a == 0 || b == 0 || a % b == 0 || b % a == 0) cout << 1 << endl;
  else cout << 2 << endl;
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
