// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
typedef long long ll;

const int N = 15;

int n;
int vis[1 << N];
int ans[1 << N + 1];

bool solve(int cur, int steps = 1) {
  if(steps == (1 << n))
    return true;
  int nxt = (cur << 1) & ((1 << n) - 1);
  for(int it = 0; it < 2; it++) {
    if(!vis[nxt]) {
      vis[nxt] = steps + 1;
      if(solve(nxt, steps + 1))
        return true;
      vis[nxt] = 0;
    }
    nxt |= 1;
  }
  return false;
}

int main()
{
  cin >> n;
  vis[0] = 1;
  solve(0);
  for(int i = 0; i < n; i++)
    cout << '0';
  for(int i = 1; i < (1 << n); i++) {
    ans[vis[i]] = i & 1;
  }
  for(int i = 2; i < 1 + (1 << n); i++)
    cout << ans[i];
  cout << endl;
  return 0;
}
