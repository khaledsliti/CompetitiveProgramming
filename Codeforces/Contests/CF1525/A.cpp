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
    int k;
    cin >> k;
    int ans = 1e9;
    for(int i = 0; i <= 500; i++) {
      for(int j = 0; j <= 500; j++) {
        if(!i && !j) continue;
        if((100 * i) % (i + j) == 0 && 100 * i / (i + j) == k) {
          ans = min(ans, i + j);
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}
