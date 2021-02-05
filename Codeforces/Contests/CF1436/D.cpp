#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;

const int N = 2e5 + 5;
const ll INF = 1e18;

int n;
int a[N];
vector<int> g[N];
ll val[N];
bool ok;

ll dfs(ll mx, int cur) {
  if(!sz(g[cur])) {
    if(a[cur] > mx) ok = false;
    return mx - a[cur];
  }
  ll acc = 0;
  for(int nxt: g[cur]) {
    acc = min(acc + dfs(mx, nxt), INF);
  }
  if(a[cur] > acc) ok = false;
  return acc - a[cur];
}

bool check(ll mid) {
  ok = true;
  dfs(mid, 0);
  return ok;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  for(int i = 1; i < n; i++) {
    int p; cin >> p;
    g[--p].pb(i);
  }
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }

  // for(int i = 0; i <= 10; i++) {
  //   cout << i << " " << check(i) << endl;
  // }
  // return 0;

  ll lo = 0, hi = INF, best = 0;
  while(lo <= hi) {
    ll mid = (lo + hi) / 2;
    if(check(mid)) {
      best = mid;
      hi = mid - 1;
    } else {
      lo = mid + 1;
    }
  }
  cout << best << endl;
  return 0;
}
