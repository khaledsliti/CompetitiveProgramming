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

int n;
int a[N], b[N];

void solve() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for(int i = 0; i < n; i++) {
    cin >> b[i];
  }
  for(int i = 0; i < n; i++) {
    cout << *lower_bound(b, b + n, a[i]) - a[i] << " ";
  }
  cout << endl;
  vector<int> ok(n);
  for(int i = n - 2; i >= 0; i--) {
    if(b[i] >= a[i + 1]) {
      ok[i + 1] = 1;
    }
  }
  vector<int> nxt(n, -1);
  int x = -1;
  for(int i = n - 1; i >= 0; i--) {
    if(ok[i]) {
      if(x == -1) {
        x = i;
      }
      nxt[i] = x;
    } else {
      x = -1;
    }
  }
  for(int i = 0; i < n; i++) {
    if(i < n - 1 && nxt[i + 1] != -1) {
      cout << b[nxt[i + 1]] - a[i] << " ";
    } else {
      cout << b[i] - a[i] << " ";
    }
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
