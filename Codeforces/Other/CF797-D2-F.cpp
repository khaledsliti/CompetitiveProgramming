// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 5003;
const long long INF = 0x3F3F3F3F3F3F;

int n, m;
int x[N];
pair<int, int> a[N];
long long dp[2][N];

int main()
{
  cin >> n >> m;
  for(int i = 0 ; i < n ; i++)
    cin >> x[i];
  sort(x, x + n);
  for(int i = 0 ; i < m ; i++) {
    cin >> a[i].first >> a[i].second;
  }
  sort(a, a + m);
  int cur = 0, prv = 1;
  for(int i = 1 ; i <= n ; i++)
    dp[cur][i] = INF;
  dp[cur][0] = 0;
  for(int j = 0 ; j < m ; j++) {
    cur ^= 1, prv ^= 1;
    dp[cur][0] = 0;
    deque<pair<long long, int>> dq;
    dq.push_back({0, 0});
    long long cost = 0;
    for(int i = 1 ; i <= n ; i++) {
      cost += abs(x[i - 1] - a[j].first);
      while(dq.size() && dq.back().first > dp[prv][i] - cost)
        dq.pop_back();
      dq.push_back({dp[prv][i] - cost, i});
      if(a[j].second < i - dq.front().second)
        dq.pop_front();
      dp[cur][i] = dq.front().first + cost;
    }
  }
  if(dp[cur][n] >= INF) dp[cur][n] = -1;
  cout << dp[cur][n] << endl;
  return 0;
}
