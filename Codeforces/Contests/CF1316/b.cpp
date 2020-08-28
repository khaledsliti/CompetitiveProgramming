// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 5005;

int n;
string s;

string solve(int k)
{
  string a = s.substr(0, k - 1);
  string b = s.substr(k - 1, sz(s) - k + 1);
  int cnt = sz(s) - k + 1;
  if(cnt & 1)
    reverse(all(a));
  return b + a;
}

void solve()
{
  cin >> n;
  cin >> s;
  map<string, vector<int>> sol;
  for(int k = 1 ; k <= n ; k++) {
    string cur = solve(k);
    sol[cur].pb(k);
  }
  cout << sol.begin()->first << endl;
  cout << sol.begin()->second[0] << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while(t--){
    solve();
  }
  return 0;
}
