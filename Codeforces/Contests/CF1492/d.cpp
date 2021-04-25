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

int a, b, k;
string x, y;

int main()
{
  cin >> a >> b >> k;

  for(int i = 0; i < b; i++) {
    x += '1';
  }
  for(int i = 0; i < a; i++) {
    x += '0';
  }

  y = x;

  if(a == 0 || b == 1) {
    if (k > 0) cout << "NO" << endl;
    else cout << "YES\n" << x << "\n" << y << endl;
    return 0;
  }
  if(k >= a + b - 1) {
    cout << "NO" << endl;
    return 0;
  }

  if(k <= a) {
    y[b - 1] = '0';
    y[b + k - 1] = '1';
  } else {
    y[a + b - 1] = '1';
    y[b - 1] = '0';
    k -= a;
    if(k > 0) {
      y[b - 1] = '1';
      y[b - k - 1] = '0';
    }
  }

  cout << "YES" << endl;
  cout << x << endl << y << endl;

  return 0;
}
