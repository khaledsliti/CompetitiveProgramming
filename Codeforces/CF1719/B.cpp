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

int n, k;

void solve() {
  cin >> n >> k;
  k %= 4;
  if (k == 0) {
    cout << "NO" << endl;
    return;
  }
  if (n % 4 == 0 || k != 1) {
    vector<int> a, b, c;
    for(int i = 1; i <= n; i++) {
      if(i % 4 == 0) {
        b.push_back(i);
      } else if((i + k) % 4 == 0) {
        a.push_back(i);
      } else {
        c.push_back(i);
      }
    }
    if(sz(a) + sz(b) < sz(c)) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
      int j = 0;
      for(int i = 0; i < sz(a); i++) {
        cout << a[i] << " " << c[j++] << endl;
      }
      for(int i = 0; i < sz(b); i++) {
        cout << c[j++] << " " << b[i] << endl;
      }
    }
    return;
  }
  if (n >= 6) {
    cout << "YES" << endl;
    cout << "1 6" << endl << "3 2" << endl << "5 4" << endl;
    vector<int> a, b, c;
    for(int i = 7; i <= n; i++) {
      if(i % 4 == 0) {
        b.push_back(i);
      } else if((i + k) % 4 == 0) {
        a.push_back(i);
      } else {
        c.push_back(i);
      }
    }
    int j = 0;
    for(int i = 0; i < sz(a); i++) {
      cout << a[i] << " " << c[j++] << endl;
    }
    for(int i = 0; i < sz(b); i++) {
      cout << c[j++] << " " << b[i] << endl;
    }
  }
  if (n == 2) {
    cout << "YES" << endl;
    cout << "1 2" << endl;
  }
  return;
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