#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const long long oo = 1e18;
const int N = 2e5 + 5;

int n, m, k, q;
int L[N], R[N], nxt[N];
vector<int> safe;
long long dp[N][2][2];

long long go_up(int row, int col, int b1, int b2);

long long solve(int row, int col, int b1, int b2)
{
  long long& r = dp[row][b1][b2];
  if(r != -1)
    return r;
  r = oo;
  r = min(r, abs(col - R[row]) + abs(R[row] - L[row]) + min(go_up(row, L[row], 0, 0), go_up(row, L[row], 0, 1)));
  r = min(r, abs(col - L[row]) + abs(L[row] - R[row]) + min(go_up(row, R[row], 1, 0), go_up(row, R[row], 1, 1)));
  return r;
}

long long go_up(int row, int col, int b1, int b2)
{
  if(nxt[row] >= n)
    return 0;
  int idx = upper_bound(all(safe), col) - safe.begin();
  if(b2 == 0){
    --idx;
    if(idx >= 0)
      return abs(col - safe[idx]) + nxt[row] - row + solve(nxt[row], safe[idx], b1, b2);
  }else{
    if(idx < sz(safe))
      return abs(col - safe[idx]) + nxt[row] - row + solve(nxt[row], safe[idx], b1, b2);
  }
  return 1e18;
}

long long solve()
{
  if(L[0] <= R[0])
    return solve(0, 0, 0, 0);
  return safe[0] + nxt[0] + solve(nxt[0], safe[0], 0, 0);
}

int main()
{
  while(~scanf("%d%d%d%d", &n, &m, &k, &q)){
    for(int i = 0 ; i < n ; i++)
      L[i] = m, R[i] = -1;
    while(k--){
      int r, c;
      scanf("%d%d", &r, &c);
      --r, --c;
      L[r] = min(L[r], c);
      R[r] = max(R[r], c);
    }
    nxt[n - 1] = n;
    for(int i = n - 2 ; i >= 0 ; i--){
      if(L[i + 1] <= R[i + 1])
        nxt[i] = i + 1;
      else
        nxt[i] = nxt[i + 1];
    }
    safe.clear();
    while(q--){
      int c;
      scanf("%d", &c);
      safe.pb(--c);
    }
    sort(all(safe));
    memset(dp, -1, sizeof dp);
    cout << solve() << endl;
  }
  return 0;
}
