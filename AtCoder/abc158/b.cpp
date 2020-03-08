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
  long long n, a, b;
  cin >> n >> a >> b;
  long long q = n / (a + b);
  long long r = n % (a + b);
  cout << q * a + min(r, a) << endl;
  return 0;
}
