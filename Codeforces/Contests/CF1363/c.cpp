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

const int N = 1001;

string First = "Ayush";
string Second = "Ashish";

int n, x;
vector<int> g[N];

void solve() {
  scanf("%d%d", &n, &x);
  --x;
  for(int i = 0; i < n; i++)
    g[i].clear();
  int d = 0;
  for(int i = 1; i < n; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    --u, --v;
    if(u == x || v == x) d++;
    g[u].pb(v);
    g[v].pb(u);
  }
  if(d <= 1) {
    cout << First << endl;
    return;
  }
  int sum = n - 1;
  if(sum & 1) cout << First << endl;
  else cout << Second << endl;
}

int main()
{
  int T;
  scanf("%d", &T);
  while(T--) {
    solve();
  }
  return 0;
}
