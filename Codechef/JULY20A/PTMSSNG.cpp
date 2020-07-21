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

int main()
{
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) {
    int n;
    cin >> n;
    int x, y;
    map<int, int> xx, yy;
    for(int i = 0; i < 4 * n - 1; i++) {
      cin >> x >> y;
      xx[x]++;
      yy[y]++;
    }
    for(auto v: xx)
      if(v.second & 1)
        x = v.first;
    for(auto v: yy)
      if(v.second & 1)
        y = v.first;
    cout << x << " " << y << endl;
  }
  return 0;
}
