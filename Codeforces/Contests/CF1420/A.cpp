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

const int N = 5e4 + 5;

int n, a[N];

void solve() {
  cin >> n;
  bool t = true;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    if(i > 0 && a[i] >= a[i - 1]) {
      t = false;
    }
  }
  if(t) cout << "NO" << endl;
  else cout << "YES" << endl;
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
