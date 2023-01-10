// RedStone
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

const int N = 405;

int n;
int m;
int dist[N][N];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m;
  memset(dist, -1, sizeof dist);
  queue<pair<int, int>> q;
  q.push({0, 0});
  dist[0][0] = 0;
  while(!q.empty()) {
    int i = q.front().first;
    int j = q.front().second;
    q.pop();
    for(int a = 0; a * a <= m; a++) {
      int b2 = m - a * a;
      int sb2 = sqrt(b2);
      if(sb2 * sb2 == b2) {
        vector<int> nis = {i - a, i + a}, njs = {j - sb2, j + sb2};
        for(int ni : nis) {
          if(ni < 0 || ni >= n) continue;
          for(int nj : njs) {
            if(nj < 0 || nj >= n) continue;
            if(dist[ni][nj] == -1) {
              dist[ni][nj] = 1 + dist[i][j];
              q.push({ni, nj});
            }
          }
        }
      }
    }
  }
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      cout << dist[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
