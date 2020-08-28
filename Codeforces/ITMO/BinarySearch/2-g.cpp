// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rsort(a, b) sort(a, b), reverse(a, b)
typedef long long ll;

const int N = 51;
const int K = 20;

int n, k;
int a[N];

bool check(ll total) {
  ll need = total * k;
  ll sum = 0;
  for(int i = 0; i < n; i++) {
    sum += min((ll)a[i], total);
  }
  return sum >= need;
}

int main()
{
  cin >> k >> n;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  ll l = 0, r = 1e16, best = 0;
  while(l <= r) {
    ll mid = l + (r - l) / 2;
    if(check(mid)) {
      best = mid;
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  cout << best << endl;
  return 0;
}
