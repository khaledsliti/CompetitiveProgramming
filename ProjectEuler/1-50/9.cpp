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

int main()
{
  for(int a = 1; a <= 1000; a++)
    for(int b = a + 1; b <= 1000; b++) {
      int c = 1000 - a - b;
      if(1LL * a * a + 1LL * b * b != 1LL * c * c) continue;
      cout << a * b * c << endl;
      return 0;
    }
  cout << -1 << endl;
  return 0;
}
