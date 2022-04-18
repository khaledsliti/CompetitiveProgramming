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

const int N = 156;
const long long INF = 1e18;

int n;
int k[N], h[N];
long long dp[N];

long long get(long long x) {
  return x * (x + 1) / 2;
}

long long solve(int i, int st) {
  if(i >= n) return 0;
  long long& r = dp[i];
  if(r != -1) return r;
  r = INF;
  int expStart = 1e9 + 5;
  for(int j = i; j < n; j++) {
    expStart = min(expStart, k[j] - h[j] + 1);
    if(expStart < st)
      break;
    int len = k[j] - expStart + 1;
    r = min(r, get(len) + solve(j + 1, k[j] + 1));
  }
  return r;
}

void solve() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> k[i];
  }
  for(int i = 0; i < n; i++) {
    cin >> h[i];
  }
  for(int i = 0; i <= n; i++) {
    dp[i] = -1;
  }
  cout << solve(0, 1) << endl;
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
