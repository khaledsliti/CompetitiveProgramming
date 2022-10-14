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

const int N = 1e5 + 5;

int n, k;
long long pr[N];

void solve() {
  cin >> n >> k;
  for(int i = 0; i < n; i++) {
    cin >> pr[i];
    if(i > 0) {
      pr[i] += pr[i - 1];
    }
  }
  long long ans = pr[n - 1] - 1LL * n * k;
  vector<int> r;
  for(int i = n - 1; i >= 0; i--) {
    int cur = pr[i] - (i > 0 ? pr[i - 1] : 0);
    r.push_back(cur >> 1);
    long long res = (i > 0 ? pr[i - 1] : 0) - 1LL * i * k;
    vector<int> tmp;
    for(auto& x: r) {
      res += x;
      x >>= 1;
      if(x > 0) {
        tmp.push_back(x);
      }
    }
    swap(tmp, r);
    ans = max(ans, res);
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
