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

void solve() {
  int n;
  cin >> n;
  int a[2] = {0, 0};
  for(int i = 0; i < n; i++) {
    int x; cin >> x;
    if((x & 1) != (i & 1)) a[x & 1]++;
  }
  if(a[0] != a[1]) cout << -1 << endl;
  else cout << a[0] << endl;
}

int main()
{
  int T;
  cin >> T;
  while(T--) {
    solve();
  }
  return 0;
}
