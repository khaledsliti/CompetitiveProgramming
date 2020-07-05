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

const int N = 301;

int n, m;
int a[N][N];

bool inGrid(int x, int y) {
  return x >= 0 && x < n && y >= 0 && y < m;
}

int nei(int x, int y) {
  int ans = 0;
  if(x > 0) ans++;
  if(x < n - 1) ans++;
  if(y > 0) ans++;
  if(y < m - 1) ans++;
  return ans;
}

int main()
{
  int T;
  cin >> T;
  while(T--) {
    cin >> n >> m;
    int a[n][m];
    bool good = true;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        cin >> a[i][j];
        int target = nei(i, j);
        if(target < a[i][j]) {
          good = false;
        } else {
          a[i][j] = target;
        }
      }
    }
    if(good) {
      cout << "YES" << endl;
      for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
          cout << a[i][j] << " ";
        cout << endl;
      }
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
