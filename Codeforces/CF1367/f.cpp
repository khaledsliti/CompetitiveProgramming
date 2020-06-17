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
int arr[N];
int id[N];
vector<int> pos[N];
int dp[N];

void solve() {
  cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
    a[i] = arr[i];
    pos[i].clear();
  }
  sort(all(a));
  a.resize(unique(all(a)) - begin(a));
  for(int i = 0; i < n; i++) {
    arr[i] = lower_bound(all(a), arr[i]) - begin(a);
    pos[arr[i]].push_back(i);
  }
  for(int i = 0; i < n; i++)
    dp[i] = 0;
  int best = 0;
  for(int i = n - 1; i >= 0; i--) {
    dp[i] = sz(pos[arr[i]]) - (lower_bound(all(pos[arr[i]]), i) - begin(pos[arr[i]]));
    if(i == pos[arr[i]].front()) {
      int last = pos[arr[i]].back();
      if(arr[i] + 1 < n && sz(pos[arr[i] + 1])) {
        int v = arr[i] + 1;
        int idx = lower_bound(all(pos[v]), last) - begin(pos[v]);
        if(idx < sz(pos[v])) {
          dp[i] = max(dp[i], sz(pos[arr[i]]) + dp[pos[v][idx]]);
        }
      }
    }
    best = max(best, dp[i]);
    if(arr[i] > 0) {
      int p = arr[i] - 1;
      best = max(best, dp[i] + (lower_bound(all(pos[p]), i) - begin(pos[p])));
    }
  }
  cout << n - best << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) {
    solve();
  }
  return 0;
}
