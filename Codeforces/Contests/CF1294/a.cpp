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
  while(T--){
    int a, b, c, n;
    cin >> a >> b >> c >> n;
    int mx = max(max(a, b), c);
    int sum = 3 * mx - a - b - c;
    if(sum > n){
      cout << "NO" << endl;
      continue;
    }else{
      n -= sum;
      if(n % 3 == 0) cout << "YES" << endl;
      else cout << "NO" << endl;
    }
  }
  return 0;
}
