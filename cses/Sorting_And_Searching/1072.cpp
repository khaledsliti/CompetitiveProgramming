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
  int n;
  cin >> n;
  for(int i = 1; i <= n; i++) {
    ll a = i * i;
    ll b = a * (a - 1) / 2;
    if(i > 2)
      b -= 4 * (i - 1) * (i - 2);
    cout << b << endl;
  }
  return 0;
}
