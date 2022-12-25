// RedStone
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

int n, m;
string sol;

void f(string cur) {
  if(sol == "-1") {
    sol = cur;
    return;
  }
  if(sz(cur) > sz(sol)) {
    sol = cur;
    return;
  }
  if (sz(cur) == sz(sol)) {
    sol = max(sol, cur);
    return;
  }
}

int main()
{
  cin >> n >> m;
  sol = "-1";
  for(int d = 1; d <= 9; d++) {
    int r = 0;
    int cnt = -1;
    for(int i = 1; i <= n; i++) {
      r = (r * 10LL + d) % m;
      if(r == 0) {
        cnt = i;
      }
    }
    if(cnt != -1) {
      f(string(cnt, char('0' + d)));
    }
  }
  cout << sol << endl;
  return 0;
}
