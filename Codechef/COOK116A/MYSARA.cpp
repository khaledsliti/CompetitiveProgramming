// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 5e4 + 5;
const int Mod = 1e9 + 7;

int n;
int B[N];
int po[N];

int main()
{
  po[0] = 1;
  for(int i = 1 ; i < N ; i++) {
    po[i] = po[i - 1] * 2 % Mod;
  }
  int T;
  scanf("%d", &T);
  while(T--) {
    scanf("%d", &n);
    for(int i = 0 ; i < n ; i++) {
      scanf("%d", B + i);
    }
    long long ans = 1;
    bool valid = true;
    for(int b = 0 ; b < 30 ; b++) {
      for(int i = 0 ; i < n ; i++) {
        if(B[i] & (1 << b)) {
          for(int j = i + 1 ; j < n ; j++)
            if(!(B[j] & (1 << b)))
              valid = false;
          ans = (ans * po[n - i - 1]) % Mod;
          break;
        }
      }
    }
    if(!valid) ans = 0;
    cout << ans << endl;
  }
  return 0;
}
