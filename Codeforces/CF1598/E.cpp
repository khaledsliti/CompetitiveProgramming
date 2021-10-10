#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
long long c2(long long n) { return n * (n - 1) / 2; }
long long c3(long long n) { return n * (n - 1) * (n - 2) / 6; }
typedef long long ll;

const int N = 1007;

int n, m, q;
long long ans;
int a[N][N];

int calc(int x, int y, int dx, int dy) {
  int cnt = 0;
  while(true) {
    x += dx, y += dy;
    if(x < 0 || y < 0 || x >= n || y >= m || a[x][y] == 1)
      break;
    cnt++;
    swap(dx, dy);
  }
  return cnt;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m >> q;
  ans += n * m;
  for(int i = 0; i < n; i++) {
    int len = calc(i, 0, 1, 0) + 1;
    ans += c2(len);
  }
  for(int j = 0; j < m; j++) {
    int len = calc(0, j, 0, 1) + 1;
    ans += c2(len);
  }
  while(q--) {
    int x, y; cin >> x >> y;
    --x, --y;
    int l = calc(x, y, -1, 0);
    int r = calc(x, y, 0, 1);
    ans += (a[x][y] == 1 ? 1 : -1) * ((l + 1) * (r + 1) - 1);
    l = calc(x, y, 0, -1);
    r = calc(x, y, 1, 0);
    ans += (a[x][y] == 1 ? 1 : -1) * ((l + 1) * (r + 1) - 1);
    ans += (a[x][y] == 1 ? 1 : -1);
    a[x][y] ^= 1;
    cout << ans << endl;
  }

  return 0;
}
