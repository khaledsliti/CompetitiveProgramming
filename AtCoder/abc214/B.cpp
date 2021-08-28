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
  int s, t;
  cin >> s >> t;
  int ans = 0;
  for(int i = 0; i <= s; i++) {
    for(int j = 0; j <= s; j++) {
      for(int k = 0; k <= s; k++) {
        if(i + j + k <= s && i * j * k <= t) {
          ans++;
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}
