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

const int N = 25;

int n;
ll a[N][N];

int main()
{
  cin >> n;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(i & 1) {
        a[i][j] = 0;
      } else {
        a[i][j] = 1LL << i + j;
      }
    }
  }
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++)
      cout << a[i][j] << " ";
    cout << endl;
  }
  cout.flush();

  int q;
  cin >> q;
  while(q--) {
    ll k;
    cin >> k;
    --k;
    vector<pair<int, int>> sol;
    int x = 0, y = 0;
    while(x < n - 1 || y < n - 1) {
      sol.push_back({x + 1, y + 1});
      if(x == n - 1) y++;
      else if(y == n - 1) x++;
      else if((x & 1)) {
        if((k & a[x + 1][y]) == a[x + 1][y]) x++;
        else y++;
      } else {
        if((k & a[x][y + 1]) == a[x][y + 1]) y++;
        else x++;
      }
    }
    sol.push_back({n, n});
    for(int i = 0; i < sz(sol); i++)
      cout << sol[i].first << " " << sol[i].second << endl;
  }
  cout.flush();
  return 0;
}
