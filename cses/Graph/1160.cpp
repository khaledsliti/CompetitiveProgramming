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

const int N = 2e5 + 5;

int n, q;
int nxt[N], par[N], cycle_index[N];
int col[N];
vector<vector<int>> cycles;
vector<vector<int>> 

int main()
{
  cin >> n >> q;
  for(int i = 0; i < n; i++) {
    cin >> nxt[i];
    --nxt[i];
  }

  for(int i = 0; i < n; i++) {
    col[i] = 0;
    cycle_index[i] = -1;
  }

  for(int i = 0; i < n; i++) {
    if(col[i] == 0) {
      for(int cur = i; ; cur = nxt[cur]) {
        if(col[cur] == 1) {
          vector<int> cycle {cur};
          for(int k = nxt[cur]; k != cur; k = nxt[k]) {
            cycle.push_back(k);
          }
          cycles.push_back(cycle);
          break;
        } else {
          col[cur] = 1;
        }
      }
      for(int cur = i; col[cur] != 2; cur = nxt[cur])
        col[cur] = 2;
    }
  }

  for(int i = 0; i < sz(cycles); i++) {
    for(int u: cycles[i]) {
      cycle_index[u] = i;
    }
  }

  while(q--) {
    int a, b;
    cin >> a >> b;
    --a, --b;
  }
  return 0;
}
