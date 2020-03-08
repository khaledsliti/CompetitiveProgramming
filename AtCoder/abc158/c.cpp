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
  int a, b;
  cin >> a >> b;
  for(int x = 1 ; x <= 1e6 ; x++) {
    if(x * 2 / 25 == a && x / 10 == b)
      return cout << x << endl, 0;
  }
  cout << -1 << endl;
  return 0;
}
