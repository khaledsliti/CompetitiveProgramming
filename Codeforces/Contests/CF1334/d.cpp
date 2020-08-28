// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

void solve() {
  long long n, L, R;
  vector<long long> sol;
  cin >> n >> L >> R;
  sol.clear();
  long long st = 1;
  for(long long a = 1 ; a < n ; a++) {
    for(long long j = max(L, st) ; j <= min(R, st + 2 * (n - a) - 1) ; j++) {
      long long p = j - st;
      if(!(p & 1)) sol.push_back(a);
      else sol.push_back(a + (p + 1) / 2);
    }
    st += 2 * (n - a);
  }
  if(R == n * (n - 1) + 1) sol.push_back(1);
  for(int i = 0 ; i < sz(sol) ; i++)
    printf("%I64d ", sol[i]);
  printf("\n");
}

int main()
{
  int t;
  cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}
