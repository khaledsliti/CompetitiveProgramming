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



int main()
{
  int r1, r2, c1, c2;
  cin >> r1 >> c1 >> r2 >> c2;
  int ans = 3;
  if(r1 == r2 && c1 == c2) {
    ans = 0;
  }
  for(int dx = -20; dx <= 20; dx++) {
    for(int dy = -20; dy <= 20; dy++) {
      int nx = r1 + dx, ny = c1 + dy;
      int cost = (abs(nx - r1) + abs(ny - c1) + 2) / 3;
      if(nx == r2 && ny == c2) {
        ans = min(ans, cost);
      }
      if(nx + ny == r2 + c2 || nx - ny == r2 - c2) {
        ans = min(ans, 1 + cost);
      }
      if(((nx + ny) & 1) == ((r2 + c2) & 1)) {
        ans = min(ans,  2 + cost);
      }
    }
  }
  cout << ans << endl;
  return 0;
}
