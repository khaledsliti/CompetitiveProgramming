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

const int N = 1001;

int n, m;
string s[N];
int vis[N][N];
int rooms;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};


void dfs(int x, int y) {
  vis[x][y] = 1;
  for(int k = 0; k < 4; k++) {
    int nx = x + dx[k];
    int ny = y + dy[k];
    if(nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] && s[nx][ny] == '.') {
      dfs(nx, ny);
    }
  }
}

int main()
{
  cin >> n >> m;
  for(int i = 0; i < n; i++)
    cin >> s[i];
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++)
      if(!vis[i][j] && s[i][j] == '.') {
        rooms++;
        dfs(i, j);
      }
  }
  cout << rooms << endl;
  return 0; 
}
