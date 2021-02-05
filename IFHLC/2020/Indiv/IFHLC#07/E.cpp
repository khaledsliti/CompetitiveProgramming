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
  int m, a, b, c;
  cin >> m >> a >> b >> c;
  if(a > b) swap(a, b);
  for(int i = 0; i <= a; i++) {
    int w = a + b - i;
    if(w > m) continue;
    if(m - i >= c) {
      cout << "possible" << endl;
      return 0;
    }
  }
  cout << "impossible" << endl;
  return 0;
}
