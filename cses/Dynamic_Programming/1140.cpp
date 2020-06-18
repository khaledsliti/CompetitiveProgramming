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

struct P{
  int st, en, cost;
  bool operator<(const P& other) const {
    return st < other.st;
  }
};


int n;
vector<P> pr;

int main()
{
  cin >> n;
  pr.resize(n);
  for(int i = 0; i < n; i++) {
    cin >> pr[i].st >> pr[i].en >> pr[i].cost;
  }
  sort(all(pr));
  vector<ll> dp(n + 1);
  dp[n] = 0;
  for(int i = n - 1; i >= 0; i--) {
    dp[i] = dp[i + 1];
    int idx = lower_bound(all(pr), (P){pr[i].en + 1, 0, 0}) - begin(pr);
    dp[i] = max(dp[i], pr[i].cost + dp[idx]);
  }
  cout << dp[0] << endl;
  return 0;
}
