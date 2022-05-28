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

const int Mod = 998244353;
const int N = 1e5 + 5;

int ans[N];

int main()
{
  // for(int n = 1; n <= 10; n++) {
  //   vector<int> a;
  //   for(int i = 0; i < n; i++) {
  //     a.push_back(i + 1);
  //   }
  //   int ans = 0;
  //   do {
  //     int g = 0;
  //     for(int i = 0; i < n; i++) {
  //       g = __gcd(g, (i + 1) * a[i]);
  //     }
  //     if(g > 1) ans++;
  //   } while(next_permutation(all(a)));
  //   cout << n << " = " << ans << endl;
  // }

  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  ans[2] = 1;
  for(int i = 4, cur = 2; i < N; i += 2, cur += 1) {
    ans[i] = 1LL * ans[i - 2] * cur % Mod * cur % Mod;
  }

  int T;
  cin >> T;
  while(T--) {
    int n; cin >> n; cout << ans[n] << endl;
  }
  return 0;
}
