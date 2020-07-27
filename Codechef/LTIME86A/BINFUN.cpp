// We only fail when we stop trying
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

const int N = 1e5 + 5;
const int A = 32;

int n;
int arr[N];
vector<int> v[A];

ll calc(ll a, ll b) {
  int len_a = 64 - __builtin_clzll(a);
  int len_b = 64 - __builtin_clzll(b);
  return (a << len_b) + b - (b << len_a) - a;
}

ll solve() {
  ll best = LLONG_MIN;
  for(int i = 0; i < A; i++) {
    for(int cur: v[i]) {
      for(int j = 0; j < A; j++) {
        if(!sz(v[j])) continue;
        best = max(best, calc(cur, v[j].front()));
        best = max(best, calc(v[i].front(), v[j].back()));
      }
    }
  }
  return best;
}

int main()
{
  int T;
  scanf("%d", &T);
  while(T--) {
    scanf("%d", &n);
    for(int i = 0; i < A; i++)
      v[i].clear();
    for(int i = 0; i < n; i++) {
      scanf("%d", &arr[i]);
      v[32 - __builtin_clz(arr[i])].pb(arr[i]);
    }
    if(n == 1) {
      printf("0\n");
      continue;
    }
    for(int i = 0; i < A; i++) {
      sort(all(v[i]), [](int a, int b) {
        return a > b;
      });
    }
    ll ans = solve();
    printf("%lld\n", ans);
  }
  return 0;
}
