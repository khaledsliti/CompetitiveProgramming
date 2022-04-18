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
  int n;
  cin >> n;
  vector<int> v(n);
  for(int i = 0; i < n; i++) {
    cin >> v[i];
  }
  if(n <= 2) {
    for(int i = 0; i < n; i++) {
      cout << v[i] << " ";
    }
    cout << endl;
    return;
  }
  if(v.front() == n) {
    v.erase(v.begin());
  } else if(v.back() == n) {
    v.pop_back();
  } else {
    cout << -1 << endl;
    return;
  }
  for(int i = sz(v) - 2; i >= 0; i--) {
    cout << v[i] << " ";
  }
  cout << n << " ";
  cout << v.back() << endl;
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
