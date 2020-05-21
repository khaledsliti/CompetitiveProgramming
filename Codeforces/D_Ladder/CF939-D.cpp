// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
typedef long long ll;

const int N = 1e5 + 5;

int n;
string a, b;
int par[26];

int fs(int x) {
  return x == par[x] ? x : par[x] = fs(par[x]);
}

int main()
{
  cin >> n >> a >> b;
  for(int i = 0; i < 26; i++) {
    par[i] = i;
  }
  vector<array<char, 2>> sol;
  for(int i = 0; i < n; i++) {
    if(a[i] != b[i]) {
      int x = fs(a[i] - 'a');
      int y = fs(b[i] - 'a');
      if(x != y) {
        sol.push_back({char(x + 'a'), char(y + 'a')});
        par[x] = y;
      }
    }
  }
  cout << sz(sol) << endl;
  for(int i = 0; i < sz(sol); i++)
    cout << sol[i][0] << " " << sol[i][1] << endl;
  return 0;
}
