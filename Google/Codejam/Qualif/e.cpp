// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 53;

int n, k;
int ans[N][N];

void solve() {
  scanf("%d%d", &n, &k);
  for(int i = 0 ; i < n ; i++)
    for(int j = 0; j < n ; j++)
      ans[i][j] = 0;
  if(n <= 3) {

  } else {
    bool found = false;
    for(int a = 1 ; a <= n && !found ; a++) {
      for(int b = 1 ; b <= n && !found ; b++) {
        if(a == b) continue;
        int c = k - (n - 2) * a - b;
        if(c >= 1 && c <= n && a != c) {
          
        }
      }
    }
  }
}

int main()
{
  int t, tc(1);
  scanf("%d", &t);
  while(t--) {
    printf("Case #%d: ", tc++);
    solve();
  }
  return 0;
}
