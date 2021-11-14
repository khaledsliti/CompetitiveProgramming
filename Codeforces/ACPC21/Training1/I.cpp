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
  int n, k;
  cin >> n >> k;
  vector<int> arr(n);
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sort(all(arr));
  int ans = 0;
  for(int i = 0; i < n; i++) {
    ans++;
    int j = i;
    while(j < n && arr[j] - arr[i] < k) {
      j++;
    }
    i = j - 1;
  }
  cout << ans << endl;
}


int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

#ifndef LOCAL
  freopen("bowling.in", "r", stdin);
#endif

  int T;
  cin >> T;
  while(T--) {
    solve();
  }
  return 0;
}