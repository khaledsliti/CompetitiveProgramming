// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define X first
#define D second

const int N = 2e5 + 5;
const int MOD = 998244353;
const int oo = 2e9;

int n;
pair<int, int> robot[N];
int dp[N];
int st[N << 2];
long long sol[N];

int get(int cur, int s, int e, int i, int j)
{
  if(s > j || e < i)
    return -oo;
  if(s >= i && e <= j)
    return st[cur];
  int l = 2 * cur + 1;
  int r = 2 * cur + 2;
  int mid = (s + e) / 2;
  return max(get(l, s, mid, i, j), get(r, mid + 1, e, i, j));
}

void update(int cur, int s, int e, int idx, int val)
{
  if(s > idx || e < idx)
    return;
  if(s == e){
    st[cur] = val;
    return;
  }
  int l = 2 * cur + 1;
  int r = 2 * cur + 2;
  int mid = (s + e) / 2;
  update(l, s, mid, idx, val);
  update(r, mid + 1, e, idx, val);
  st[cur] = max(st[l], st[r]);
}

int main()
{
  cin >> n;
  for(int i = 0 ; i < n ; i++) {
    cin >> robot[i].X >> robot[i].D;
  }
  sort(robot, robot + n);
  for(int i = n - 1 ; i >= 0 ; i--) {
    int right = lower_bound(robot, robot + n, make_pair(robot[i].X + robot[i].D, -oo)) - robot - 1;
    if(right > i)
      dp[i] = get(0, 0, n - 1, i + 1, right);
    else
      dp[i] = i + 1;
    update(0, 0, n - 1, i, dp[i]);
  }
  sol[n] = 1;
  for(int i = n - 1 ; i >= 0 ; i--) {
    sol[i] = (sol[i + 1] + sol[dp[i]]) % MOD;
  }
  cout << sol[0] << endl;
  return 0;
}
