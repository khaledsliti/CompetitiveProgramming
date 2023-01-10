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

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;
  auto dist = [&](int i, int j) {
    if(i <= j) return j - i;
    return j + n - i;
  };
  vector<int> arr(n);
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  vector<int> cnt(n, 0);
  for(int i = 0; i < n; i++) {
    int cur = arr[i];
    for(int j = cur - 1; j <= cur + 1; j++) {
      int idx = (j + n) % n;
      cnt[dist(i, idx)]++;
    }
  }
  int ans = 0;
  for(int i = 0; i < n; i++) {
    ans = max(ans, cnt[i]);
  }
  cout << ans << endl;
  return 0;
}
