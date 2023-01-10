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
  int n; cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(all(a));
  if(a[0] == a[n - 1]) {
    cout << 1LL * n * (n - 1) << endl;
    return;
  }
  int x = 0, y = 0;
  for(int i = 0; i < n; i++) {
    if(a[i] == a[0]) {
      x++;
    }
    if(a[i] == a[n - 1]) {
      y++;
    }
  }
  cout << 2LL * x * y << endl;
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
