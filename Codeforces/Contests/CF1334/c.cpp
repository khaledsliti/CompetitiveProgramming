// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 3e5 + 5;

int n;
long long a[N], b[N];

void solve() {
  scanf("%d", &n);
  long long ans = 0;
  for(int i = 0 ; i < n ; i++)
    scanf("%I64d %I64d", &a[i], &b[i]);
  long long add = 1e18;
  for(int i = 0 ; i < n ; i++) {
    int j = (i + 1) % n;
    if(b[i] < a[j]) ans += a[j] - b[i], add = min(add, b[i]);
    else add = min(add, a[j]);
  }
  printf("%I64d\n", ans + add);
}

int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
    solve();
  return 0;
}
