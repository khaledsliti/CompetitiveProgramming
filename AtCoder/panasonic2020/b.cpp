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
  unsigned long long n, m;
  cin >> n >> m;
  if(min(n, m) == 1) cout << 1 << endl;
  else cout << ((n + 1) / 2) * ((m + 1) / 2) + (n / 2) * (m / 2) << endl;
  return 0;
}
