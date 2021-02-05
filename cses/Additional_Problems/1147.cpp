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

const int N = 1007;

int n, m;
string s[N];
int L[N][N], R[N][N];

int main()
{
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    cin >> s[i];
  }
  for(int i = 0; i < n; i++) {
    for(int j = m - 1, cnt = 0; j >= 0; j--) {
      if(s[i][j] == '*') cnt = 0;
      else cnt++;
      R[i][j] = cnt;
    }
    for(int j = 0, cnt = 0; j < m; j++) {
      if(s[i][j] == '*') cnt = 0;
      else cnt++;
      L[i][j] = cnt;
    }
  }

  int ans = 0;
  for(int j = 0; j < m; j++) {
    for(int i = n - 1; i >= 0; i--) {
      if(s[i][j] == '.') {
        int l = m, r = m, k = i;
        while(k >= 0 && s[k][j] == '.') {
          l = min(l, L[k][j]), r = min(r, R[k][j]);
          ans = max(ans, (l + r - 1) * (i - k + 1));
          k--;
        }
        i = k;
      }
    }
  }

  cout << ans << endl;
  return 0;
}
