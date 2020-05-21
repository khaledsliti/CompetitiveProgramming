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

bool check(int x, int y) {
  int a = x / 10, b = x % 10;
  int c = y / 10, d = y % 10;
  if(b == 0 && d == 0) return false;
  // a / c == x / y
  if(b == d && a * y == x * c) return true;
  // a / d
  if(b == c && a * y == x * d) return true;
  if(a == d && b * y == x * c || a == c && b * y == x * d) return true;
  return false;
}

int main()
{
  ll x = 1, y = 1;
  for(int a = 11; a <= 99; a++)
    for(int b = 11; b < a; b++) {
      if(check(a, b)) {
        x *= a, y *= b;
      }
    }
  cout << x / __gcd(x, y) << endl;
  return 0;
}
