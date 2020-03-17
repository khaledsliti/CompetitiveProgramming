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
  long long a, b, c;
  cin >> a >> b >> c;
  long long r = c - a - b;
  if(r < 0) return cout << "No" << endl, 0;
  r = r * r;
  if(4 * a * b < r) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
