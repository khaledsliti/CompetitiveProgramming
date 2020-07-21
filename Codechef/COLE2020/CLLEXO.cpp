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

const int N = 1e7 + 5;

int n, m;
vector<vector<char>> s;
vector<vector<bool>> added, reachable;
int dx[] = { 1, 0 };
int dy[] = { 0, 1 };
vector<pair<int, int>> alp[26];

void bfs() {
  reachable.clear();
  reachable.resize(n, vector<bool>(m, 0));
  queue<pair<int, int>> q;
  q.push({n - 1, m - 1});
  reachable[n - 1][m - 1] = 1;
  while(q.empty() == false) {
    int x = q.front().first;
    int y = q.front().second;
    q.pop();
    if(x - 1 >= 0 && s[x - 1][y] != '#' && !reachable[x - 1][y]) {
      reachable[x - 1][y] = 1;
      q.push({x - 1, y});
    }
    if(y - 1 >= 0 && s[x][y - 1] != '#' && !reachable[x][y - 1]) {
      reachable[x][y - 1] = 1;
      q.push({x, y - 1});
    }
  }
}

int main()
{
  int T;
  scanf("%d", &T);
  while(T--) {
    scanf("%d%d", &n, &m);
    added.clear();
    added.resize(n, vector<bool>(m, 0));
    s.clear();
    s.resize(n, vector<char>(m));
    for(int i = 0; i < n; i++)
      for(int j = 0; j < m; j++)
        scanf(" %c", &s[i][j]);
    bfs();
    vector<pair<int, int>> pos;
    pos.push_back({0, 0});
    for(int it = 0; it < n + m - 2; it++) {
      int x = pos.front().first;
      int y = pos.front().second;
      printf("%c", s[x][y]);
      vector<pair<int, int>> tmp;
      char mn = 'z';
      for(int i = 0; i < sz(pos); i++) {
        int x = pos[i].first;
        int y = pos[i].second;
        for(int k = 0; k < 2; k++) {
          int nx = x + dx[k];
          int ny = y + dy[k];
          if(nx < n && ny < m && reachable[nx][ny] && !added[nx][ny]) {
            added[nx][ny] = 1;
            tmp.push_back({nx, ny});
            mn = min(mn, s[nx][ny]);
          }
        }
      }
      pos.clear();
      for(int i = 0; i < sz(tmp); i++) {
        int x = tmp[i].first;
        int y = tmp[i].second;
        if(s[x][y] == mn)
          pos.push_back({x, y});
      }
    }
    printf("%c\n", s[n - 1][m - 1]);
  }
  return 0;
}
