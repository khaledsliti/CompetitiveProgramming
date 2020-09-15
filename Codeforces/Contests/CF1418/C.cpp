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
int a[N], dp[N][2];

int solve(int cur, int t) {
  if(cur >= n) return 0;
  int& r = dp[cur][t];
  if(r != -1) return r;
  r = n + 1;
  if(t == 0) {
    r = min(r, solve(cur + 1, 1));
    if(cur + 1 < n) r = min(r, solve(cur + 2, 1));
  } else {
    r = min(r, a[cur] + solve(cur + 1, 0));
    if(cur + 1 < n) r = min(r, a[cur] + a[cur + 1] + solve(cur + 2, 0));
  }
  return r;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int T;
  cin >> T;
  while(T--) {
    cin >> n;
    for(int i = 0; i< n ; i++) {
      cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
      dp[i][0] = dp[i][1] = -1;
    }
    cout << solve(0, 1) << endl;
  }
  return 0;
}
