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

int n, k;
int l1, r1, l2, r2;

void solve() {
  scanf("%d%d", &n, &k);
  scanf("%d%d", &l1, &r1);
  scanf("%d%d", &l2, &r2);
  if(l1 > l2) {
    swap(l1, l2);
    swap(r1, r2);
  }
  int diff = max(0, l2 - r1);
  int intersection = max(0, min(r1, r2) - l2);
  int united = max(r2, r1) - l1;
  int add = united - intersection;

  if(1LL * intersection * n >= k) {
    cout << 0 << endl;
    return;
  }

  k -= 1LL * intersection * n;

  ll best = LLONG_MAX;
  for(int i = 1; i <= n; i++) {
    ll cost = 1LL * diff * i;
    if(1LL * add * i >= k) {
      cost += k;
    } else {
      cost += 1LL * add * i;
      ll rem = k - 1LL * add * i;
      cost += 2LL * rem;
    }
    best = min(best, cost);
  }
  cout << best << endl;
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
