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

const int N = 2e5 + 5;

int n;
int t[N], d[N];
vector<int> topic[N];

long long choose3(long long n) {
  return n * (n - 1) * (n - 2) / 6;
}

long long choose2(long long n) {
  return n * (n - 1) / 2;
}

void solve() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    topic[i].clear();
  }
  map<int, int> fr_diff;
  for(int i = 0; i < n; i++) {
    cin >> t[i] >> d[i];
    topic[--t[i]].push_back(--d[i]);
    fr_diff[d[i]]++;
  }
  long long total = choose3(n);
  long long ans = 0;
  for(int i = 0; i < n; i++) {
    long long cur = 0;
    for(int j: topic[i]) {
      cur += 1LL * (sz(topic[i]) - 1) * (fr_diff[j] - 1);
    }
    ans += cur;
  }
  ans = total - ans;
  cout << ans << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int T;
  cin >> T;
  while(T--) {
    solve();
  }
  return 0;
}
