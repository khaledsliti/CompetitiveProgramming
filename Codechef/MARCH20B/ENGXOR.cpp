// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 1e5 + 5;
const int A = 30;

void solve() {
  int n, q;
  scanf("%d%d", &n, &q);
  int odd = 0, even = 0;
  for(int i = 0 ; i < n ; i++) {
    int a; scanf("%d", &a);
    if(__builtin_popcount(a) & 1) odd++;
    else even++;
  }
  while(q--) {
    int p; scanf("%d", &p);
    int isOdd = __builtin_popcount(p) & 1;
    if(!isOdd) {
      printf("%d %d\n", even, odd);
    } else {
      printf("%d %d\n", odd, even);
    }
  }
}

int main()
{
  int T;
  scanf("%d", &T);
  while(T--) {
    solve();
  }
  return 0;
}
