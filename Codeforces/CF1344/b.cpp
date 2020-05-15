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

const int N = 1010;

int n, m;
char s[N][N];
int vis[N][N];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main()
{
  scanf("%d%d", &n, &m);
  for(int i = 0 ; i < n ; i++)
    scanf("%s", s[i]);
  for(int i = 0 ; i < n ; i++) {
    int cnt = 0;
    for(int j = 0 ; j < m ; j++) {
      if(s[i][j] == '#') {
        int k = j;
        while(k < m && s[i][k] == '#')
          k++;
        cnt++;
        j = k - 1;
      }
    }
    if(cnt > 1) {
      cout << -1 << endl;
      return 0;
    }
  }
  for(int j = 0 ; j < m ; j++) {
    int cnt = 0;
    for(int i = 0 ; i < n ; i++) {
      if(s[i][j] == '#') {
        int k = i;
        while(k < n && s[k][j] == '#')
          k++;
        cnt++;
        i = k - 1;
      }
    }
    if(cnt > 1) {
      cout << -1 << endl;
      return 0;
    }
  }
  int ans = 0;
  for(int i = 0 ; i < n ; i++)
    for(int j = 0 ; j < m ; j++) {
      if(!vis[i][j] && s[i][j] == '#') {
        ++ans;
        queue<pair<int, int>> q;
        q.push({i, j});
        vis[i][j] = 1;
        while(!q.empty()) {
          int x = q.front().first;
          int y = q.front().second;
          q.pop();
          for(int k = 0 ; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(nx >= 0 && ny >=0 && nx < n && ny < m && !vis[nx][ny] && s[nx][ny] == '#') {
              q.push({nx, ny});
              vis[nx][ny] = 1;
            }
          }
        }
      }
    }
  cout << ans << endl;
  return 0;
}
