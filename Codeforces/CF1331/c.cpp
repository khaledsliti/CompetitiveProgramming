// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

// And after happily lived ever they
// And they lived happily after ever 

int main()
{
  int n;
  cin >> n;
  int perm[] = {5, 0, 2, 3, 1, 4};
  int ans = 0;
  for(int i = 0 ; i < 6 ; i++) {
    int cur = (n & (1 << perm[i])) != 0;
    ans = (ans << 1) | cur;
  }
  cout << ans << endl;
  return 0;
}
