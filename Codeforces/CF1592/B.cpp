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
  vector<int> a(n), b(n);
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    b[i] = a[i];
  }
  sort(all(b));
  for(int i = 0; i < n; i++) {
    if(a[i] != b[i] && (i < k && n - 1 - i < k)) {
      cout << "NO" << endl;
      return;
    }
  }
  cout << "YES" << endl;
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
