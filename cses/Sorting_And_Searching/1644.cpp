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

int n, a, b;
int x[N];
ll acc[N];

int main()
{
  cin >> n >> a >> b;
  b++;
  for(int i = 1; i <= n; i++) {
    cin >> x[i];
    acc[i] = acc[i - 1] + x[i];
  }
  ll best = -1e18;
  multiset<ll> cur;
  for(int i = 1; i <= n; i++) {
    if(i - a >= 0) {
      cur.insert(acc[i - a]);
    }
    if(i - b >= 0) {
      cur.erase(cur.find(acc[i - b]));
    }
    if(!cur.empty()) {
      best = max(best, acc[i] - *cur.begin());
    }
  }
  cout << best << endl;
  return 0;
}
