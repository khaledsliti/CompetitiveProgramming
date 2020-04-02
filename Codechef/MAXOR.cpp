// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 20;

int n;
long long c[1 << N], dp[1 << N];

void solve() {
  scanf("%d", &n);
  for(int i = 0 ; i < (1 << N) ; i++)
    c[i] = 0;
  for(int i = 0 ; i < n ; i++) {
    int a;
    scanf("%d", &a);
    c[a]++;
  }
  for(int i = 0 ; i < (1 << N) ; i++)
    dp[i] = c[i];
  for(int i = 0 ; i < N ; i++)
    for(int mask = 0 ; mask < (1 << N) ; mask++)
      if(mask & (1 << i))
        dp[mask] += dp[mask ^ (1 << i)];
  long long ans = 0;
  for(int i = 0 ; i < (1 << N) ; i++) {
    int lt = dp[i] - c[i];
    ans += c[i] * lt + c[i] * (c[i] - 1) / 2;
  }
  cout << ans << endl;
}

int main()
{
  int T;
  scanf("%d", &T);
  while(T--)
    solve();
  return 0;
}
