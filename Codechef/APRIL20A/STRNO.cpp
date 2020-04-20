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
  int t;
  cin >> t;
  while(t--) {
    int x, k;
    cin >> x >> k;
    int cnt = 0;
    for(int i = 2 ; i * i <= x ; i++) {
      while(x % i == 0) {
        cnt++;
        x /= i;
      }
    }
    if(x > 1)
      cnt++;
    cout << (cnt >= k) << endl;
  }
  return 0;
}
