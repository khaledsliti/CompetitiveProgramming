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

const int N = 500001;

int n;
int arr[N];

int abs(int x) { return x >= 0 ? x : -x; }

int main()
{
  ios::sync_with_stdio(false);
  cin >> n;

  ll s = 0;
  bool neg = false, pos = false;
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
    s += abs(arr[i]);
    if(arr[i] < 0) neg = true;
    else pos = true;
  }
  if(n == 1) {
    cout << arr[0] << endl;
  } else if(neg && pos) {
    cout << s << endl;
  } else {
    ll ans = -1e18;
    for(int i = 0; i + 1 < n; i++) {
      int diff = -abs(arr[i] - arr[i + 1]);
      ans = max(ans, s - abs(arr[i]) - abs(arr[i + 1]) - diff);
    }
    cout << ans << endl;
  }

  return 0;
}
