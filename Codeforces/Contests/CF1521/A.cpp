// Guess Who's Back
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;



int main()
{
  int T;
  cin >> T;
  while(T--) {
    ll a, b;
    cin >> a >> b;
    if(b == 1) cout << "NO" << endl;
    else {
      cout << "YES" << endl;
      ll x = a;
      ll y = a * b;
      ll z = a * (b + 1);
      cout << x << " " << y << " " << z << endl;
    }
  }
  return 0;
}
