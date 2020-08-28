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
  int T;
  cin >> T;
  while(T--) {
    int n, k;
    cin >> n >> k;
    vector<int> d;
    for(int i = 1; i * i <= n; i++)
      if(n % i == 0) {
        d.push_back(i);
        if(i * i < n)
          d.push_back(n / i);
      }
    sort(all(d));
    for(int i = 0; i < sz(d); i++) {
      if(n / d[i] <= k) {
        cout << d[i] << endl;
        break;
      }
    }
  }
  return 0;
}
