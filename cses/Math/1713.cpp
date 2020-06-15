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

const int N = 1e6 + 4;

int smf[N];

int main()
{
  for(int i = 0; i < N; i++)
    smf[i] = i;
  for(int i = 2; i * i < N; i++) {
    if(smf[i] == i) {
      for(int j = i * i; j < N; j += i)
        smf[j] = min(smf[j], i);
    }
  }
  int T;
  cin >> T;
  while(T--) {
    int a;
    cin >> a;
    int ans = 1;
    while(a > 1) {
      int p = smf[a];
      int cur = 1;
      while(p == smf[a]) {
        a /= p;
        cur++;
      }
      ans *= cur;
    }
    cout << ans << endl;
  }
  return 0;
}
