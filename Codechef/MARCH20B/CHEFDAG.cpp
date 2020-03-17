// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 502;

int n, k;
int p[N], c[N][N];
int vis[N], match[N], sol[N];

bool findMatch(int u) {
  vis[u] = 1;
  for(int v = 0 ; v < n ; v++) {
    if(!c[u][v]) continue;
    if(match[v] == -1 || !vis[match[v]] && findMatch(match[v])) {
      match[v] = u;
      sol[u] = v;
      return true;
    }
  }
  return false;
}

void solve() {
  cin >> n >> k;
  for(int i = 0 ; i < n ; i++) {
    for(int j = 0 ; j < n ; j++)
      c[i][j] = i != j;
  }
  for(int i = 0 ; i < k ; i++)
    for(int j = 0 ; j < n ; j++) {
      cin >> p[j];
      p[j]--;
      for(int l = 0 ; l < j ; l++) {
        c[p[j]][p[l]] = 0;
      }
    }
  for(int i = 0 ; i < n ; i++)
    match[i] = -1, sol[i] = -1;
  int res = n;
  for(int i = 0 ; i < n ; i++) {
    for(int j = 0 ; j < n ; j++)
      vis[j] = 0;
    if(findMatch(i))
      res--;
  }
  cout << res << endl;
  for(int i = 0 ; i < n ; i++) {
    if(i) cout << " ";
    cout << sol[i] + 1;
  }
  cout << endl;
}

int main()
{
  int T;
  cin >> T;
  while(T--)
    solve();
  return 0;
}
