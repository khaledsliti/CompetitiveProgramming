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
  int T;
  cin >> T;
  while(T--) {
    pair<int, int> a[4];
    for(int i = 0; i < 4; i++) {
      cin >> a[i].first;
      a[i].second = i;
    }
    sort(a, a + 4);
    int x = a[2].second, y = a[3].second;
    if(x > y) swap(x, y);
    if(x <= 1 && y >= 2) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
  return 0;
}
