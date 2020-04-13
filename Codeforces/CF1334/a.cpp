// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

int n;

void solve() {
  cin >> n;
  int a = 0, b = 0;
  bool good = true;
  for(int i = 0 ; i < n ; i++) {
    int x, y;
    cin >> x >> y;
    if(x < a) good = false;
    else {
      int add = x - a;
      if(y < b || add + b < y)
        good = false;
    }
    a = x, b = y;
  }
  if(good) puts("YES");
  else puts("NO");
}

int main()
{
  int T;
  cin >> T;
  while(T--)
    solve();
  return 0;
}
