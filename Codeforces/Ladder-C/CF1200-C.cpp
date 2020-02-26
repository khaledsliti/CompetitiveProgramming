// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

int main()
{
  long long n, m;
  int q;
  cin >> n >> m >> q;
  long long g = __gcd(n, m);
  m /= g;
  n /= g;
  while(q--){
     int sx, ex;
     long long sy, ey;
     cin >> sx >> sy >> ex >> ey;
     sy = --sy / (sx == 1 ? n : m);
     ey = --ey / (ex == 1 ? n : m);
     cout << (sy == ey ? "YES" : "NO") << endl;
  }
  return 0;
}
