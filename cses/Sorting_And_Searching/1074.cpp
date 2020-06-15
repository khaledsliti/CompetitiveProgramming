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

const int N = 2e5 + 5;

int n;
int a[N];
ll p[N];

ll get(int l, int r) {
  if(l > r) return 0;
  return p[r] - (l > 0 ? p[l - 1] : 0);
}

int main()
{
  cin >> n;
  for(int i = 0; i < n; i++)
    cin >> a[i];
  sort(a, a + n);
  for(int i = 0; i < n; i++) {
    p[i] = a[i];
    if(i) p[i] += p[i - 1];
  }
  ll best = 1e18;
  for(int i = 0; i < n; i++) {
    ll cur = (1LL * a[i] * i) - get(0, i - 1) + get(i + 1, n - 1) - (1LL * a[i] * (n - 1 - i));
    best = min(best, cur);
  }
  cout << best << endl;
  return 0;
}
