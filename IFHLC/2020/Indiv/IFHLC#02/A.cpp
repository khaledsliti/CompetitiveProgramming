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



int main()
{
  freopen("document.in", "r", stdin);
  freopen("document.out", "w", stdout);
  int n;
  cin >> n;
  int ok[n][7];
  memset(ok, 0, sizeof ok);
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < 5; j++) {
      cin >> ok[i][j];
    }
  }
  int ans = 0, d = 0;
  for(int i = 0; i < n; i++) {
    while(ok[i][d] == 0) {
      ans++;
      d = (d + 1) % 7;
    }
    ans++;
    d = (d + 1) % 7;
  }
  cout << ans << endl;
  return 0;
}
