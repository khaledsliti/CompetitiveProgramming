/********************************************************************************************************
  Author: RedStone

  Problem link:
    https://codeforces.com/contest/1107/problem/F

  Idea:
    https://codeforces.com/blog/entry/64833

  Complexity:
    Time: O(N^2)
    Memory: O(N^2)
********************************************************************************************************/
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 505;

struct offer{
  int a, b, k;
  bool operator<(const offer& rhs) const{
    return b > rhs.b;
  }
};

istream& operator>>(istream& cin, offer& o){
  return cin >> o.a >> o.b >> o.k;
}
ostream& operator<<(ostream& cout, offer& o){
  return cout << o.a << " " << o.b << " " << o.k;
}

int n;
offer off[N];
long long dp[N][N];
bool done[N][N];

long long solve(int cur, int taken)
{
  if(cur >= n)
    return 0;
  long long& r = dp[cur][taken];
  if(done[cur][taken])
    return r;
  done[cur][taken] = true;
  r = solve(cur + 1, taken);
  long long cost = off[cur].a - 1LL * taken * off[cur].b;
  r = max(r, cost + solve(cur + 1, taken + 1));
  cost = off[cur].a - 1LL * off[cur].k * off[cur].b;
  return r = max(r, cost + solve(cur + 1, taken));
}

int main()
{
  cin >> n;
  for(int i = 0 ; i < n ; i++)
    cin >> off[i];
  sort(off, off + n);
  memset(done, 0, sizeof done);
  cout << solve(0, 0) << endl;
  return 0;
}
