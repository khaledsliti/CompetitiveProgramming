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

int main()
{
  int T;
  cin >> T;
  while(T--) {
    int n, k;
    cin >> n >> k;
    if(n >= k && n % 2 == 0 && 2 * k <= n) {
      cout << "YES" << endl;
      for(int i = 0 ; i < k - 1 ; i++) {
        cout << "2 ";
      }
      cout << n - 2 * (k - 1) << endl;
      continue;
    }
    if(n >= k && (n - k) % 2 == 0) {
      cout << "YES" << endl;
      for(int i = 0 ; i < k - 1 ; i++)
        cout << "1 ";
      cout << n - k + 1 << endl;
      continue;
    }
    cout << "NO" << endl;
  }
  return 0;
}
