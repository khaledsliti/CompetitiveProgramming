// Guess Who's Back
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

const int N = 4e5 + 5;

int r, c, n;
vector<vector<char>> s;
int a[N];
vector<vector<int>> nxt;
map<pair<int, int>, int> id;
vector<vector<int>> g;


int idx[N], low[N], comp_of[N];
int ncomp, cur_idx;
stack<int> st;
int in[N];



void addEdge(int x, int y ,int i, int j) {
  int a = id[{x, y}];
  int b = id[{i, j}];
  g[a].push_back(b);
}



void dfs(int u) {
  idx[u] = low[u] = ++cur_idx;
  st.push(u);
  for(int v: g[u]) {
    if(idx[v] == -1) { // Gray to White
      dfs(v);
      low[u] = min(low[u], low[v]);
    } else if(comp_of[v] == -1) { // Gray to gray
      low[u] = min(low[u], low[v]);
    }
  }
  if(low[u] == idx[u]) {
    while(true) {
      int t = st.top(); st.pop();
      comp_of[t] = ncomp;
      if(t == u) break;
    }
    ncomp++;
  }
}

void scc()
{
  memset(idx, -1, n * sizeof(idx[0]));
  memset(comp_of, -1, n * sizeof(comp_of[0]));
  ncomp = cur_idx = 0;
  for(int i = 0 ; i < n ; i++)
    if(idx[i] == -1)
      dfs(i);
}



int main()
{
  scanf("%d%d", &r, &c);
  s.resize(r, vector<char>(c));
  n = 0;
  for(int i = 0; i < r; i++) {
    for(int j = 0; j < c; j++) {
      scanf(" %c", &s[i][j]);
      if(s[i][j] == '#') {
        id[{i, j}] = n++;
      }
    }
  }
  for(int i = 0; i < c; i++) {
    scanf("%d", a + i);
  }

  nxt.resize(r + 1, vector<int>(c));
  for(int j = 0; j < c; j++) {
    nxt[r][j] = r;
    for(int i = r - 1; i >= 0; i--) {
      if(s[i][j] == '#') nxt[i][j] = i;
      else nxt[i][j] = nxt[i + 1][j];
    }
  }

  if(n == 0) {
    cout << 0 << endl;
    return 0;
  }

  g.resize(n);
  for(int i = 0; i < r; i++) {
    for(int j = 0; j < c; j++) {
      if(s[i][j] == '#') {
        if(i > 0 && s[i - 1][j] == '#') {
          addEdge(i, j, i - 1, j);
        }
        if(nxt[i + 1][j] < r) {
          addEdge(i, j, nxt[i + 1][j], j);
        }
        if(j > 0 && nxt[i][j - 1] < r) {
          addEdge(i, j, nxt[i][j - 1], j - 1);
        }
        if(j + 1 < c && nxt[i][j + 1] < r) {
          addEdge(i, j, nxt[i][j + 1], j + 1);
        }
      }
    }
  }

  // for(int i = 0; i < n; i++) {
  //   for(int j : g[i]) {
  //     cout << i << " " << j << endl;
  //   }
  // }

  scc();

  for(int i = 0; i < n; i++) {
    for(int j: g[i]) {
      if(comp_of[i] != comp_of[j]) {
        in[comp_of[j]]++;
      }
    }
  }

  int ans = 0;
  for(int i = 0; i < ncomp; i++) {
    ans += in[i] == 0;
  }
  cout << ans << endl;
  return 0;
}
