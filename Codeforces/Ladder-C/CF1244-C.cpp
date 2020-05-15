// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

long long n, p, w, d;


int main()
{
  cin >> n >> p >> w >> d;
  for(int y = 0; y < w; y++) {
    long long v = p - y * d;
    long long x = v / w;
    if(v % w == 0 && x >= 0 && x + y <= n) {
      cout << x << " " << y << " " << n - x - y << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}
