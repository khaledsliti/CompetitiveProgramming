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

// -8  4 -2 -6 4 7 1
// -8 -6

int main()
{
  int T;
  cin >> T;
  while(T--) {
    int n;
    cin >> n;
    vector<int> a(n), t(n);
    for(int i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<int> b;
    for(int i = 0; i < n; i++) {
      cin >> t[i];
      if(!t[i]) b.push_back(a[i]);
    }
    sort(rall(b));
    for(int i = n - 1; i >= 0; i--) {
      if(!t[i]) {
        a[i] = b.back();
        b.pop_back();
      }
    }
    for(int i = 0; i < n; i++) {
      cout << a[i] << " ";
    }
    cout << endl;
  }
  return 0;
}
