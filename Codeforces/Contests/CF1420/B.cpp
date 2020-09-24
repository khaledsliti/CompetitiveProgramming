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

const int N = 1e5 + 5;

int n;
int a[N];

int get(int x) {
  for(int i = 30; i >= 0; i--) {
    if((1 << i) <= x)
      return i;
  }
  return -1;
}

void solve() {
  cin >> n;
  map<int, int> cnt;
  long long ans = 0;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    int idx = get(a[i]);
    ans += cnt[idx];
    cnt[idx]++;
  }
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
