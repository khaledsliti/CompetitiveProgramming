// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;

const int N = 1e5 + 5;

int n;
int cost[3][N], in[N];
vector<int> g[N];
int ord[N];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for(int i = 0; i < 3; i++)
    for(int j = 0; j < n; j++)
      cin >> cost[i][j];
  
  for(int i = 1; i < n; i++) {
    int a, b; cin >> a >> b;
    --a, --b;
    g[a].pb(b);
    g[b].pb(a);
    in[a]++, in[b]++;
  }
  for(int i = 0; i < n; i++)
    if(in[i] > 2) {
      cout << "-1" << endl;
      return 0;
    }
  int cur;
  for(int i = 0; i < n; i++)
    if(in[i] == 1) {
      cur = i;
      break;
    }
  ord[0] = cur;
  cur = g[cur][0];
  ord[1] = cur;
  int last = ord[0];
  for(int i = 2; i < n; i++) {
    int new_cur = g[cur][0] + g[cur][1] - last;
    ord[i] = new_cur;
    last = cur;
    cur = new_cur;
  }
  int col[] = {0, 1, 2};
  ll best = LLONG_MAX;
  int sol[n];
  do {
    ll cur = 0;
    for(int i = 0, j = 0; i < n; i++, j = (j + 1) % 3) {
      cur += cost[col[j]][ord[i]];
    }
    if(best > cur) {
      best = cur;
      for(int i = 0, j = 0; i < n; i++, j = (j + 1) % 3) {
        sol[ord[i]] = col[j] + 1;
      }
    }
  } while(next_permutation(col, col + 3));
  cout << best << endl;
  for(int i = 0; i < n; i++)
    cout << sol[i] << " ";
  cout << endl;
  return 0;
}
