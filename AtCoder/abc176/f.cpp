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

const int N = 6007;
const int Inf = 1e9;

int n;
int a[N];
int dp[N][N];

template<class T>
void maxi(T& mx, T val) {
  mx = max(mx, val);
}

int main()
{
  cin >> n; n *= 3;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      dp[i][j] = -Inf;
    }
  }
  dp[a[0]][a[1]] = 0;
  int add = 0;
  for(int i = 2; i + 2 < n; i += 3) {
    sort(a + i, a + i + 3);
    int p = a[i], q = a[i + 1], r = a[i + 2];
    if(p == r) {
      add++;
      continue;
    }
    if(p == q || q == r) {
      int x = p == q ? p : r;
      int y = p == q ? r : p;
      // have: x x y
      maxi(dp[x][x], dp[y][y] + 1);
      
      for(int k = 1; k <= n; k++) {
        maxi(dp[k][y], 1 + dp[k][x]);
        maxi(dp[y][k], 1 + dp[k][x]);
      }
    }
    
  }
  int best = 0;
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      best = max(best, dp[i][j] + (i == j && j == a[n - 1]));
    }
  }
  cout << best + add << endl;
  return 0;
}
