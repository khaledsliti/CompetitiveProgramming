#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 51;

int n;
string s[N];
int dist[2][N][N];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool in(int nx, int ny)
{
  return (nx >= 0 && nx < n && ny >= 0 && ny < n);
}

void bfs(pair<int, int> src, int (*dist)[N])
{
  for(int i = 0 ; i < n ; i++)
    for(int j = 0 ; j < n ; j++)
      dist[i][j] = -1;
  dist[src.first][src.second] = 0;
  queue<pair<int, int>> q;
  q.push(src);
  while(!q.empty()){
    int x = q.front().first;
    int y = q.front().second;
    q.pop();
    for(int k = 0 ; k < 4 ; k++){
      int nx = x + dx[k];
      int ny = y + dy[k];
      if(in(nx, ny) && s[nx][ny] == '0' && dist[nx][ny] == -1){
        dist[nx][ny] = 1 + dist[x][y];
        q.push({nx, ny});
      }
    }
  }
}

int main()
{
  cin >> n;
  pair<int, int> pts[2];
  for(int it = 0 ; it < 2 ; it++){
    cin >> pts[it].first >> pts[it].second;
    pts[it].first--;
    pts[it].second--;
  }
  for(int i = 0; i < n ; i++)
    cin >> s[i];
  for(int i = 0 ; i < 2 ; i++)
    bfs(pts[i], dist[i]);
  if(~dist[0][pts[1].first][pts[1].second])
    return cout << 0 << endl, 0;
  int best = 1e9;
  for(int i = 0 ; i < n ; i++){
    for(int j = 0 ; j < n ; j++){
      if(dist[0][i][j] == -1)
        continue;
      for(int k = 0 ; k < n ; k++){
        for(int l = 0 ; l < n ; l++){
          if(dist[1][k][l] == -1)
            continue;
          best = min(best, (i - k) * (i - k) + (j - l) * (j - l));
        }
      }
    }
  }
  cout << best << endl;
  return 0;
}
