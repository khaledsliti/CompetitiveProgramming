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
vector<pair<int, int>> g[N];
int ans[N];

int main()
{
  scanf("%d", &n);
  for(int i = 0 ; i < n - 1 ; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    --a, --b;
    g[a].pb({b, i});
    g[b].pb({a, i});
  }
  if(n == 2) {
    cout << 0 << endl;
    return 0;
  }
  int cur = 0;
  memset(ans, -1, sizeof ans);
  for(int i = 0 ; i < n ; i++) {
    if(sz(g[i]) == 1){
      ans[g[i][0].second] = cur++;
    }
  }
  for(int i = 0 ; i < n - 1 ; i++) {
    if(ans[i] == -1)
      ans[i] = cur++;
  }
  for(int i = 0 ; i < n - 1 ; i++)
    printf("%d\n", ans[i]);
  return 0;
}
