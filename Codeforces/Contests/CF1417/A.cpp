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

int main()
{
  int T;
  cin >> T;
  while(T--) {
    int n, k, mn = 1e9;
    cin >> n >> k;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
      cin >> v[i];
    }
    sort(all(v));
    int ans = 0;
    for(int i = 1; i < n; i++) {
      ans += (k - v[i]) / v[0];
    }
    cout << ans << endl;
  }
  return 0;
}
