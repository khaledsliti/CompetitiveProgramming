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

void solve() {
  int n, a;
  cin >> n >> a;
  vector<int> arr(n);
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sort(all(arr));
  reverse(all(arr));
  int ans = 2 * (a / (arr[0] + arr[1]));
  int rem = a % (arr[0] + arr[1]);
  if(rem > 0) ans++, rem -= arr[0];
  if(rem > 0) ans++;
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
