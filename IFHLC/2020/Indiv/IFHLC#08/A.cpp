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

const int N = 5;

int n, m, h, w;
int a[N][N], b[N][N];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);


  cin >> h >> w;
  vector<bitset<N>> grid(h);
  for(int i = 0; i < h; i++) {
    for(int j = 0; j < w; j++) {
      cin >> a[i][j];
      if(a[i][j])
        grid[i].set(j);
    }
  }

  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      cin >> b[i][j];
    }
  }

  vector<pair<int, int>> sol;
  vector<bitset<N>> rows(h);
  
  sol.push_back({0, 0});
  int best = 0;
  for(int i = 0; i < h; i++) {
    for(int j = 0; j < w; j++) {
      if(b[i][j]) {
        rows[i].set(j);
      }
    }
    best += w - (grid[i] ^ rows[i]).count();
  }

  for(int i = 0; i + h <= n; i++) {
    for(int j = w; j < m; j++) {
      // add last column
      
    }

  }


  for(int i = 0; i < sz(sol); i++) {
    cout << sol[i].first << " " << sol[i].second << endl;
  }

  return 0;
}
