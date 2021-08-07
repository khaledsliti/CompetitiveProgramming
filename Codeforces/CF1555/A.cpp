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

inline int getCeil(int a, int b) {
  if(a < 0) return 0;
  return (a + b - 1) / b;
}

int solve(int n) {
  if(n == 0) return 0;
  int best = INT_MAX;
  for(int i = 0; i <= getCeil(n, 6) + 5; i++) {
    for(int j = 0; j <= getCeil(n - i * 6, 8) + 5; j++) {
      for(int k = 0; k <= getCeil(n - i * 6 - j * 8, 10) + 5; k++) {
        if(i * 6 + j * 8 + k * 10 >= n) {
          best = min(best, i * 15 + j * 20 + k * 25);
        }
      }
    }
  }
  return best;
}

int main()
{
  int T;
  cin >> T;
  while(T--) {
    unsigned long long n;
    cin >> n;
    unsigned long long ans = n / 120 * 300;
    ans += solve(n % 120);
    cout << ans << endl;
  }
  return 0;
}
