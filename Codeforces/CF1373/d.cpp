// We only fail when we stop trying
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
int arr[N];
ll dp[N][3][3];

ll solve(int i, int t, int cnt) {
  if(i >= n) {
    if(t == 1 && cnt == 1) return -1e9;
    return 0;
  }
  ll& r = dp[i][t][cnt];
  if(r != -1) return r;
  if(t == 1) r = (i % 2 == 1 ? arr[i] : 0) + solve(i + 1, t, cnt ^ 1);
  else r = (i % 2 == 0 ? arr[i] : 0) + solve(i + 1, t, cnt ^ 1);
  if(t == 0 || t == 1 && cnt % 2 == 0) r = max(r, solve(i, t + 1, 0));
  return r; 
}

void solve () {
  cin >> n;
  for(int i = 0; i < n; i++)
    cin >> arr[i];
  for(int i = 0; i <= n; i++)
    for(int j = 0; j < 3; j++)
      for(int k = 0; k < 3; k++)
        dp[i][j][k] = -1;
  cout << solve(0, 0, 0) << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--)
    solve();
  return 0;
}
