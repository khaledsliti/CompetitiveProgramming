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

ll sqr(ll a) {
  return a * a;
}

struct item {
  ll val, t;
  ll get(ll t) const {
    return sqr(val / t) * (t - val % t) + sqr((val + t - 1) / t) * (val % t);
  }
  ll diff() const {
    return get(t + 1) - get(t);
  }
  bool operator<(const item& other) const {
    return diff() > other.diff();
  }
};

int n, k;
priority_queue<item> pq;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> k;
  for(int i = 0; i < n; i++) {
    int a; cin >> a;
    pq.push({a, 1});
  }

  int r = k - n;
  while(r--) {
    auto it = pq.top();
    pq.pop();
    it.t++;
    pq.push(it);
  }

  ll ans = 0;
  while(pq.empty() == false) {
    auto it = pq.top();
    pq.pop();
    ans += it.get(it.t);
  }
  cout << ans << endl;
  return 0;
}
