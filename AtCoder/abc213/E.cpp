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

const int N = 507;

int n, m;
string s[N];
int comp[N][N], compIdx;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
vector<int> g[N * N];

bool in(int x, int y) {
  return x >= 0 && x < n && y >= 0 && y < m;
}

void dfs(int x, int y) {
  comp[x][y] = compIdx;
  for(int k = 0; k < 4; k++) {
    int nx = x + dx[k];
    int ny = y + dy[k];
    if(in(nx, ny) && s[x][y] == s[nx][ny] && comp[nx][ny] == -1) {
      dfs(nx, ny);
    }
  }
}

void calcComp() {
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      comp[i][j] = -1;
    }
  }
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(comp[i][j] == -1) {
        if(s[i][j] == '.') {
          dfs(i, j);
        } else {
          comp[i][j] = compIdx;
        }
        compIdx++;
      }
    }
  }
}

void addEdge(int u, int v) {
  g[u].push_back(v);
}

void buildGraph() {
  for(int i = 0; i + 1 < n; i++) {
    for(int j = 0; j + 1 < m; j++) {
      vector<pair<int, int>> pts;
      for(int a = 0; a < 2; a++) {
        for(int b = 0; b < 2; b++) {
          pts.push_back({i + a, j + b});
        }
      }
      if(i > 0) {
        pts.push_back({i - 1, j});
        pts.push_back({i - 1, j + 1});
      }
      if(i + 2 < n) {
        pts.push_back({i + 2, j});
        pts.push_back({i + 2, j + 1});
      }
      if(j > 0) {
        pts.push_back({i, j - 1});
        pts.push_back({i + 1, j - 1});
      }
      if(j + 2 < m) {
        pts.push_back({i, j + 2});
        pts.push_back({i + 1, j + 2});
      }

      for(int x = 0; x < sz(pts); x++) {
        for(int y = 0; y < sz(pts); y++) {
          auto a = pts[x], b = pts[y];
          bool good = comp[a.first][a.second] != comp[b.first][b.second];
          good &= s[b.first][b.second] == '.' || (b.first >= i && b.first <= i + 1 &&
                  b.second >= j && b.second <= j + 1);
          if(good){
            addEdge(comp[a.first][a.second], comp[b.first][b.second]);
          }
        }
      }
    }
  }
}

int bfs() {
  vector<int> fr(compIdx, -1);
  queue<int> q;
  q.push(comp[0][0]);
  vector<int> dist(compIdx, -1);
  dist[comp[0][0]] = 0;
  while(q.size()) {
    int u = q.front();
    q.pop();
    for(int v: g[u]) {
      if(dist[v] == -1) {
        dist[v] = 1 + dist[u];
        q.push(v);
        fr[v] = u;
      }
    }
  }
  // for(int cur = comp[n - 1][m - 1]; cur != -1; cur = fr[cur]) {
  //   cout << cur << " ";
  // }
  // cout << endl;
  return dist[comp[n - 1][m - 1]];
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    cin >> s[i];
  }

  calcComp();

  // for(int i = 0; i < n; i++) {
  //   for(int j = 0; j < m; j++) {
  //     cout << comp[i][j] << "\t";
  //   }
  //   cout << endl;
  // }

  buildGraph();

  cout << bfs() << endl;
  return 0;
}
