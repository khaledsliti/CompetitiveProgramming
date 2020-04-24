// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

int const N = 10010, R = 1010;
long long const Inf = 1e18;

int n, m;
int d[N];
int g, r;
long long dist[N][R];

int main()
{
  cin >> n >> m;
  for(int i = 0 ; i < m ; i++) {
    cin >> d[i];
  }
  sort(d, d + m);
  cin >> g >> r;
  for(int i = 0 ; i < m ; i++)
    for(int j = 0 ; j <= g ; j++)
      dist[i][j] = -1;
  dist[0][0] = 0;
  deque<pair<int, int>> dq;
  dq.push_front({0, 0});
  while(!dq.empty()) {
    int idx = dq.front().first;
    int t = dq.front().second;
    dq.pop_front();
    if(t == g && dist[idx][0] == -1) {
      dist[idx][0] = 1 + dist[idx][t];
      dq.push_back({idx, 0});
    }
    if(idx > 0) {
      int add = d[idx] - d[idx - 1];
      if(t + add <= g && dist[idx - 1][t + add] == -1) {
        dist[idx - 1][t + add] = dist[idx][t];
        dq.push_front({idx - 1, t + add});
      }
    }
    if(idx + 1 < m) {
      int add = d[idx + 1] - d[idx];
      if(t + add <= g && dist[idx + 1][t + add] == -1) {
        dist[idx + 1][t + add] = dist[idx][t];
        dq.push_front({idx + 1, t + add});
      }
    }
  }
  long long best = -1;
  for(int i = 0 ; i < m ; i++) {
    for(int j = 0 ; j <= g ; j++) {
      int rem = d[m - 1] - d[i];
      if(rem + j <= g && dist[i][j] != -1) {
        long long cur = 1LL * dist[i][j] * (r + g) + rem + j;
        if(best == -1 || best > cur)
          best = cur;
      }
    }
  }
  cout << best << endl;
  return 0;
}
