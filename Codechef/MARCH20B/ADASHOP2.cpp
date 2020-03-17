// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

void add(vector<pair<int, int>>& sol, int r, int c) {
  sol.pb({r, c});
}

void parse4Rows(vector<pair<int, int>>& sol, int& r, int& c) {
  for(int it = 0 ; it < 3 ; it++) {
    add(sol, ++r, ++c);
    add(sol, --r, ++c);
  }
  add(sol, ++r, ++c);
  add(sol, ++r, --c);
  add(sol, ++r, ++c);
  for(int it = 0 ; it < 3 ; it++) {
    add(sol, --r, --c);
    add(sol, ++r, --c);
  }
  add(sol, --r, --c);
}

void solve() {
  int r, c;
  cin >> r >> c;
  vector<pair<int, int>> sol;
  if(r != c) {
    int s = r + c;
    r = s / 2, c = s / 2;
    add(sol, r, c);
  }
  if(r > 1) {
    r = 1, c = 1;
    add(sol, 1, 1);
  }
  parse4Rows(sol, r, c);
  add(sol, ++r, ++c);
  add(sol, ++r, --c);
  parse4Rows(sol, r, c);
  cout << sz(sol) << endl;
  for(int i = 0 ; i < sz(sol) ; i++)
    cout << sol[i].first << " " << sol[i].second << endl;
}

int main()
{
  int T;
  cin >> T;
  while(T--) {
    solve();
  }
  return 0;
}
