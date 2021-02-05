#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;

const int N = 101;

int k, n;
int a[N];

void print() {
  for(int i = 0; i < n; i++) {
      cout << a[i] << " ";
    }
    cout << endl;
}

void solve() {
  cin >> n >> k;
  for(int i = 0; i < n ;i++) {
    cin >> a[i];
  }
  if(k == 1) {
    if(a[n - 1] == a[0]) {
      cout << 1 << endl;
    } else {
      cout << -1 << endl;
    }
    return;
  }
  int ans = 1;
  int cnt = 0;
  for(int i = 0; i < n; i++) {
    if(i == 0 || a[i] != a[i - 1]) {
      cnt++;
      if(cnt > k) {
        ans++;
        cnt = 2;
      }
    }
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
