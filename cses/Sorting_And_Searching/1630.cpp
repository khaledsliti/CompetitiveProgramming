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

const int N = 2e5 + 5;

int n;
int a[N], d[N];

int main()
{
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> a[i] >> d[i];
  }
  vector<int> idx(n);
  iota(all(idx), 0);
  sort(all(idx), [&](const int& i, const int& j) {
    return a[i] < a[j];
  });
  ll ans = 0, t = 0;
  for(int i = 0; i < n; i++) {
    ans += d[idx[i]] - a[idx[i]] - t;
    t += a[idx[i]];
  }
  cout << ans << endl;
  return 0;
}
