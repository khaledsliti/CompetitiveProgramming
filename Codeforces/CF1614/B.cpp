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

const int N = 2e5 + 5;

void solve() {
  int n;
  cin >> n;
  vector<int> ans(n + 1, 0);
  vector<pair<int, int>> arr(n);
  for(int i = 0; i < n; i++) {
    cin >> arr[i].first;
    arr[i].second = i;
  }
  sort(rall(arr));
  int cur = 1;
  long long tot = 0;
  for(int i = 0; i < n; i++) {
    tot += 2LL * arr[i].first * abs(cur);
    ans[arr[i].second + 1] = cur;
    if(cur > 0) cur = -cur;
    else cur = 1 - cur;
  }
  cout << tot << endl;
  for(int i = 0; i <= n; i++) {
    cout << ans[i] << " ";
  }
  cout << endl;
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
