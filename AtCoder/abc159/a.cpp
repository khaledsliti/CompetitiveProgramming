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
  int n, m;
  cin >> n >> m;
  int ans = n * (n - 1) / 2 + m * (m - 1) / 2;
  cout << ans << endl;
  return 0;
}
