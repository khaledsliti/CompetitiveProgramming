// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 2005;

int n, l, r, h;
int a[N];
int mem[N][N];

int solve(int cur, int hour) {
  if(cur >= n) return 0;
  int& res = mem[cur][hour];
  if(res != -1) return res;
  res = 0;
  for(int it = 0 ; it < 2 ; it++) {
    int nxt = (hour + a[cur] - it) % h;
    res = max(res, (l <= nxt && nxt <= r) + solve(cur + 1, nxt));
  }
  return res;
}

int main()
{
  cin >> n >> h >> l >> r;
  for(int i = 0 ; i < n ; i++)
    cin >> a[i];
  memset(mem, -1, sizeof mem);
  cout << solve(0, 0) << endl;
  return 0;
}
