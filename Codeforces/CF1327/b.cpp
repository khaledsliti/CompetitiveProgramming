// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 1e5 + 5;

int n;
vector<int> g[N];
int match[N], p[N];


void solve() {
  for(int i = 0 ; i < n ; i++)
    match[i] = -1, p[i] = -1;
  for(int i = 0 ; i < n ; i++) {
    for(int j : g[i]) {
      if(match[j] == -1){
        p[i] = j;
        match[j] = i;
        break;
      }
    }
  }
  int a = -1, b = -1;
  for(int i = 0 ; i < n ; i++) {
    if(p[i] == -1 && a == -1)
      a = i;
    if(match[i] == -1 && b == -1)
      b = i;
  }
  if(a == -1 || b == -1) printf("OPTIMAL\n");
  else printf("IMPROVE\n%d %d\n", a + 1, b + 1);
}

int main()
{
  int T;
  scanf("%d", &T);
  while(T--) {
    scanf("%d", &n);
    for(int i = 0 ; i < n ; i++) {
      g[i].clear();
      int a; scanf("%d", &a);
      while(a--) {
        int v;
        scanf("%d", &v);
        g[i].pb(--v);
      }
    }
    solve();
  }
  return 0;
}
