#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 2005;

int n, m, k;
string s[N];
int row[N][N], col[N][N];

int main()
{
  cin >> n >> m >> k;
  for(int i = 0 ; i < n ; i++)
    cin >> s[i];
  int ans = 0;
  for(int i = 0 ; i < n ; i++) {
    for(int j = 0; j < m ; j++) {
      if(s[i][j] == '.'){
        row[i][j] = 1 + (j > 0 ? row[i][j - 1] : 0);
        col[i][j] = 1 + (i > 0 ? col[i - 1][j] : 0);
        ans += (row[i][j] >= k) + (k > 1 && col[i][j] >= k);
      }
    }
  }
  cout << ans << endl;
  return 0;
}
