// RedStone
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
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  
  int t;
  cin >> t;
  while(t--) {
    int k, a, b;
    cin >> k >> a >> b;
    if (a > b) swap(a, b);
    double b0 = 13 / 8.0 * a + 3 / 8.0;
    if(abs(b - b0) < 0.5) {
      cout << 0 << endl;
    } else {
      cout << 1 << endl;
    }
  }
  return 0;
}
