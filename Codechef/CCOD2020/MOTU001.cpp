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
  int T;
  cin >> T;
  while(T--) {
    long long a, b, c;
    cin >> a >> b >> c;
    long long q = (c - b) / a;
    cout << q * a + b << endl;
  }
  return 0;
}
