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

const int N = 18;

int n, m;
int p[N];
int x[N], y[N];
vector<vector<int>> cycles;

void read() {
  cin >> n >> m;
  for(int i = 0 ; i < n ; i++)
    cin >> p[i], p[i]--;
  for(int i = 0 ; i < m ; i++) {
    cin >> x[i] >> y[i];
    --x[i], --y[i];
  }
}

int calc(vector<int> cycle) {
  return sz(cycle) - 1;
}

int solve() {
  cycles.clear();
  vector<int> vis(n, 0);
  for(int i = 0; i < n; i++)
    if(!vis[i]) {
      vis[i] = 1;
      int cur = p[i];
      vector<int> c = {i};
      while(cur != i) {
        vis[cur] = 1;
        c.push_back(cur);
        cur = p[cur];
      }
      cycles.push_back(c);
    }
  int ans = 0;
  for(int i = 0; i < sz(cycles); i++)
    ans += calc(cycles[i]);
  return ans;
}

int main()
{
  int T;
  cin >> T;
  while(T--) {
    read();
    cout << solve() << endl;
  }
  return 0;
}
