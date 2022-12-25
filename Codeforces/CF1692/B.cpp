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
  map<int, int> f;
  for(int i = 0; i < n; i++) {
    int a; cin >> a;
    f[a]++;
  }
  vector<int> t;
  for(auto x: f) {
    t.push_back(x.second);
  }
  sort(all(t));
  while(sz(t)) {
    if(t.back() == 1) {
      break;
    }
    if(sz(t) == 1) {
      t[0] -= 2;
    } else if(t[sz(t) - 2] == 1) {
      t[sz(t) - 1] -= 2;
    } else {
      t[sz(t) - 1]--;
      t[sz(t) - 2]--;
    }
    sort(rall(t));
    while(sz(t) && t.back() == 0) {
      t.pop_back();
    }
    reverse(all(t));
  }
  cout << sz(t) << endl;
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
