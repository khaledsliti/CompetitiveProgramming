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

const int N = 2e6 + 3;

int n;
char s[N];
int f[N], z[N];

int main()
{
  scanf("%s", s);
  n = strlen(s);
  int L = 0, R = 0;
  for(int i = 1; i < n; i++){
    if(i > R) {
      L = R = i;
      while(R < n && s[R] == s[R - L]) ++R;
      z[i] = R - L;
      --R;
    } else {
      int k = i - L;
      if(z[k] <= R - i) z[i] = z[k];
      else {
        L = i;
        while(R < n  && s[R - L] == s[R]) ++R;
        z[i] = R - L;
        --R;
      }
    }
  }
  for(int k = 1; k <= n; k++) {
    bool match = true;
    for(int i = k; i < n; i += k) {
      if(z[i] < min(n - i, k))
        match = false;
    }
    if(match) cout << k << " ";
  }
  cout << endl;
  return 0;
}
/*


*/