// Guess Who's Back
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
const int L = 19;

int n;
long long arr[N];
long long dp[N][L];
int lg[N];

void pre() {
  for(int i = 0; i < n; i++) {
    dp[i][0] = arr[i];
  }
  for(int j = 1; j < L; j++) {
    for(int i = 0; i + (1 << j) <= n; i++) {
      int half = (1 << (j - 1));
      dp[i][j] = __gcd(dp[i][j - 1], dp[i + half][j - 1]);
    }
  }
}

long long query(int l, int r) {
  int s = r - l + 1;
  return __gcd(dp[l][lg[s]], dp[r - (1 << lg[s]) + 1][lg[s]]);
}

void solve() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  n--;
  for(int i = 0; i < n; i++) {
    arr[i] = abs(arr[i] - arr[i + 1]);
  }

  if(n == 0) {
    cout << 1 << endl;
    return;
  }

  // for(int i = 0; i < n; i++) {
  //   cout << arr[i] << " ";
  // }
  // cout << endl;
  pre();
  // cout << query(0, 1) << endl;
  // return ;

  int ans = 1;
  for(int i = 0; i < n; i++) {
    int right = i;
    int lo = i, hi = n - 1;
    while(lo <= hi) {
      int mid = (lo + hi) >> 1;
      if(query(i, mid) > 1) {
        right = mid;
        lo = mid + 1;
      } else {
        hi = mid - 1;
      }
    }
    if(right > i || arr[i] > 1) {
      ans = max(ans, 1 + (right - i + 1));
    }
  }
  cout << ans << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  lg[1] = 0;
  for(int i = 2; i < N; i++) {
    lg[i] = 1 + lg[i >> 1];
  }

  int T;
  cin >> T;
  while(T--) {
    solve();
  }
  return 0;
}
