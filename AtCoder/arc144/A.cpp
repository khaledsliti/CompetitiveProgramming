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
  int n; cin >> n;
  int m = 2 * n;
  cout << 2 * n << endl;
  string s = "";
  while(n >= 4) {
    s += '4';
    n -= 4;
  }
  if(n > 0) {
    s += char(n + '0');
  }
  reverse(all(s));
  cout << s << endl;
  return 0;
}
