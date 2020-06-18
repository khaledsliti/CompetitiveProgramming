// We only fail when we stop trying
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
  int n;
  cin >> n;
  for(int k = 1; k <= n; k++) {
    ll c = k * k;
    ll tot = c * (c - 1) / 2;
    if(k > 2) {
      tot -= 4 * (k - 1) * (k - 2);
    }
    cout << tot << endl;
  }
  return 0;
}
