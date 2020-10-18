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
  int T;
  cin >> T;
  while(T--) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int ans = abs(x1 - x2) + abs(y1 - y2);
    if(x1 != x2 && y1 != y2) ans += 2;
    cout << ans << endl;
  }
  return 0;
}
