// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 2e5 + 5;
const int Mod = 998244353;

int n;
int tp[N];

int solve(int k) {
  int ans = 180LL * tp[n - k - 1] % Mod;
  if(k < n - 1)
    ans += 810LL * tp[n - k - 2] % Mod * (n - k - 1) % Mod;
  return (ans % Mod);
}

int main()
{
  tp[0] = 1;
  for(int i = 1 ; i < N ; i++) {
    tp[i] = tp[i - 1] * 10LL % Mod;
  }
  while(cin >> n) {
    for(int k = 1 ; k < n ; k++) {
      printf("%d ", solve(k));
    }
    printf("10\n");
  }
  return 0;
}
