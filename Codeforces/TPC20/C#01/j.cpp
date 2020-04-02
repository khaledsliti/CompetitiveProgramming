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
  int a, b, x;
  cin >> a >> b >> x;
  if(a % x == 0 || b % x == 0 || (a + b) % x == 0) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}
