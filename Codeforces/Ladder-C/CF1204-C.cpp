// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 101;
const int oo = 1e9;

int n;
int g[N][N];

int main()
{
  cin >> n;
  for(int i = 0 ; i < n ; i++) {
    for(int j = 0 ; j < n ; j++) {
      char c; cin >> c;
      g[i][j] = c == '1' ? 1 : oo;
    }
    g[i][i] = 0;
  }
  int k;
  cin >> k;
  vector<int> path(k);
  for(int i = 0 ; i < k ; i++)
    cin >> path[i], path[i]--;
  for(int k = 0 ; k < n ; k++)
    for(int i = 0 ; i < n ; i++)
      for(int j = 0 ; j < n ; j++)
        g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
  vector<int> sol = { path[0] };
  for(int i = 0 ; i < sz(path) - 1 ; i++) {
    int j = i + 1;
    while(j < sz(path) && g[path[i]][path[j - 1]] + 1 == g[path[i]][path[j]])
      ++j;
    j--;
    if(j > i) sol.push_back(path[j]);
    i = j - 1;
  }
  printf("%d\n", sz(sol));
  for(int i = 0 ; i < sz(sol) ; i++)
    cout << sol[i] + 1 << " ";
  return 0;
}
