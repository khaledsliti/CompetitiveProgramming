#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
typedef long long ll;
const int mod = 1e9 + 7;

int main()
{
  int n, a, x, b, y;
  cin >> n >> a >> x >> b >> y;
  a--, b--, x--, y--;
  while(true){
    if(a == b){
      cout << "YES" << endl;
      return 0;
    }
    if(a == x || b == y)
      break;
    a = (a + 1) % n;
    b = (b - 1 + n) % n;
  }
  cout << "NO" << endl;
  return 0;
}