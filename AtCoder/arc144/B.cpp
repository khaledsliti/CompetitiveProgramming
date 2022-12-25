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

const int N = 3e5 + 5;

int n, a, b;
int arr[N];

bool check(ll min) {
  ll as = 0, bs = 0;
  for(int i = 0; i < n; i++) {
    if(arr[i] >= min) {
      bs += (arr[i] - min) / b;
    } else {
      as += (min - arr[i] + a - 1) / a;
    }
  }
  return bs >= as;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> a >> b;
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  ll low = 1, high = 1e9 + 1, ans = 0;
  while(low <= high) {
    ll mid = (low + high) >> 1;
    if(check(mid)) {
      ans = mid;
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  assert(ans > 0);
  cout << ans << endl;
  return 0;
}
