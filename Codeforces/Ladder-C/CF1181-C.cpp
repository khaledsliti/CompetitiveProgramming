// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 1001;

int n, m;
char s[N][N];
int lf[N][N];
int down[N][N];
int mx_lf[N][N], mx_lf_up[N][N];

int main()
{
  scanf("%d%d", &n, &m);
  for(int i = 0 ; i < n ; i++) {
    for(int j = 0 ; j < m ; j++)
      scanf(" %c", &s[i][j]);
  }
  for(int i = 0 ; i < n ; i++) {
    lf[i][m - 1] = 1;
    for(int j = m - 2 ; j >= 0 ; j--) {
      lf[i][j] = 1;
      if(s[i][j] == s[i][j + 1])
        lf[i][j] += lf[i][j + 1];
    }
  }
  for(int j = 0 ; j < m ; j++) {
    for(int i = n - 1 ; i >= 0 ; i--) {
      if(i == n - 1 || s[i][j] != s[i + 1][j]) {
        down[i][j] = 1;
        mx_lf[i][j] = lf[i][j];
      } else {
        down[i][j] = 1 + down[i + 1][j];
        mx_lf[i][j] = min(lf[i][j], mx_lf[i + 1][j]);
      }
    }
  }
  for(int j = 0 ; j < m ; j++) {
    for(int i = 0 ; i < n ; i++) {
      mx_lf_up[i][j] = lf[i][j];
      if(i > 0 && s[i][j] == s[i - 1][j])
        mx_lf_up[i][j] = min(mx_lf_up[i][j], mx_lf_up[i - 1][j]);
    }
  }
  long long ans = 0;
  for(int i = 0 ; i < n ; i++) {
    for(int j = 0 ; j < m ; j++) {
      int len = down[i][j];
      int k = i + len;
      if(k >= n || down[k][j] != len) continue;
      int l = k + len;
      if(down[l][j] < len) continue;
      int width = min(mx_lf[i][j], min(mx_lf[k][j], mx_lf_up[l + len - 1][j]));
      ans += width;
    }
  }
  cout << ans << endl;
  return 0;
}
