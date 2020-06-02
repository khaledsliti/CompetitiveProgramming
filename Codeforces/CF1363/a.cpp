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
  int n, k, odd = 0, even = 0;
  cin >> n >> k;
  for(int i = 0; i < n; i++) {
    int a;
    cin >> a;
    if(a & 1) odd++;
    else even++;
  }
  bool good = false;
  for(int i = 1; i <= k && !good; i += 2) {
    if(odd >= i && even >= k - i) {
      good = true;
    }
  }
  cout << (good ? "Yes" : "No") << endl;
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
