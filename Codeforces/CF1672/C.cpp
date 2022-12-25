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
  int n; cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int f = -1, l = -1;
  for(int i = 0; i < n - 1; i++) {
    if(a[i] == a[i + 1]) {
      if(f == -1) f = i;
      l = i + 1;
    }
  }
  int len = l - f + 1;
  if(len <= 2) cout << 0 << endl;
  else if(len <= 3) cout << 1 << endl;
  else cout << len - 3 << endl;
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
