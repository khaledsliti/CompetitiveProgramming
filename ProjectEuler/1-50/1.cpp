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

int f(int n) {
  return n * (n + 1) / 2;
}

int main()
{
  int n = 999;
  int ans = 3 * f(n / 3) + 5 * f(n / 5) - 15 * f(n / 15);
  cout << ans << endl;
  return 0;
}
