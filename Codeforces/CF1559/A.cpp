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
    int n; cin >> n;
    int ans = (1LL << 30) - 1;
    for(int i = 0; i < n; i++) {
      int a; cin >> a;
      ans &= a;
    }
    cout << ans << endl;
  }
  return 0;
}
