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
  int a, b;
  cin >> a >> b;
  int T;
  cin >> T;
  while(T--) {
    int n;
    cin >> n;
    int ans = min(n, 1000) * a + max(0, n - 1000) * b;
    cout << n << " " << ans << endl;
  }
  return 0;
}
