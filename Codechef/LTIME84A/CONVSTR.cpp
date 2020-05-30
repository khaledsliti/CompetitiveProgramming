// We only fail when we stop trying
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

const int N = 3000;

int n;
string s, t;

void solve() {
  cin >> n >> s >> t;
  vector<vector<int>> sol;
  for(char c = 'z'; c >= 'a'; c--) {
    int idx = -1;
    for(int i = 0; i < n; i++)
      if(s[i] == c) {
        idx = i;
        break;
      }
    vector<int> pos;
    for(int i = 0; i < n; i++)
      if(s[i] > t[i] && t[i] == c)
        pos.push_back(i);
    if(sz(pos) && idx == -1) {
      cout << -1 << endl;
      return;
    }
    if(!sz(pos)) continue;
    for(int i = 0; i < sz(pos); i++)
      s[pos[i]] = c;
    pos.push_back(idx);
    sol.push_back(pos);
  }
  if(s != t) {
    cout << -1 << endl;
    return;
  }
  cout << sz(sol) << endl;
  for(int i = 0; i < sz(sol); i++) {
    cout << sz(sol[i]);
    for(int j = 0; j < sz(sol[i]); j++)
      cout << " " << sol[i][j];
    cout << endl;
  }
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
