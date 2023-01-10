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

int n, m, k;
int a[N];

void solve() {
  sort(a, a + m);
  reverse(a, a + m);
  if(k > m) {
    cout << "NO" << endl;
    return;
  }
  int r = n % k;
  if(r == 0) {
    if(a[0] > n / k) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
    }
    return;
  }
  if (a[0] > n / k + 1 || a[r] > n / k) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
  }
}

void wa() {
  if(k > m) {
    cout << "NO" << endl;
    return;
  }
  int r = n % k;
  if(r == 0) {
    if(a[0] > n / k) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
    }
    return;
  }
  if (a[0] > n / k + 1) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int T;
  cin >> T;
  while(T--) {
    cin >> n >> m >> k;
    for(int i = 0 ; i < m; i++) {
      cin >> a[i];
    }
    solve();
    wa();
  }
  return 0;
}
