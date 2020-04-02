// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 2e5 + 5;

int n;
int p[N], c[N], vis[N];
vector<int> col[N];

int solve(vector<int>& v) {
  int n = sz(v);
  int ans = 1e9;
  for(int i = 1 ; i * i <= n ; i++) {
    if(n % i == 0) {
      int step = i;
      for(int it = 0 ; it < 2 ; it++) {
        for(int j = 0 ; j < step ; j++) {
          bool good = 1;
          for(int k = (j + step) % n ; k != j && good ; k = (k + step) % n) {
            good &= v[j] == v[k];
          }
          if(good) {
            ans = min(ans, step);
            break;
          }
        }
        step = n / step;
      }
    }
  }
  return ans;
}

int solve() {
  for(int i = 0 ; i < n ; i++)
    vis[i] = 0;
  int min_len = n;
  for(int i = 0 ; i < n ; i++) {
    if(!vis[i]) {
      int cur = i;
      int len = 0, same = true;
      vector<int> v = {c[cur]};
      vis[i] = 1;
      while(true) {
        cur = p[cur];
        if(cur == i)
          break;
        v.pb(c[cur]);
        vis[cur] = 1;
      }
      min_len = min(min_len, solve(v));
    }
  }
  return min_len;
}

int main()
{
  int T;
  scanf("%d", &T);
  while(T--) {
    scanf("%d", &n);
    for(int i = 0 ; i < n ; i++)
      scanf("%d", &p[i]), --p[i];
    for(int i = 0 ; i < n ; i++)
      scanf("%d", &c[i]);
    cout << solve() << endl;
  }
  return 0;
}
