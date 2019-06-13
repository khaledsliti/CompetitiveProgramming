#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 2005;

int n, m;
string s[N];
int v[N][N], h[N][N];

int main()
{
  cin >> n >> m;
  for(int i = 0 ; i < n  ; i++)
    cin >> s[i];
  for(int i = 0 ; i < n ; i++){
    for(int j = 0 ; j < m ; j++){
      if(s[i][j] == '#')
        continue;
      int k = j;
      while(k < m && s[i][k] == '.')
        k++;
      int cnt = k - j;
      for(int l = j ; l < k ; l++)
        v[i][l] = cnt;
      j = k - 1;
    }
  }
  for(int j = 0 ; j < m ; j++){
    for(int i = 0 ; i < n ; i++){
      if(s[i][j] == '#')
        continue;
      int k = i;
      while(k < n && s[k][j] == '.')
        k++;
      int cnt = k - i;
      for(int l = i ; l < k ; l++)
        h[l][j] = cnt;
      i = k - 1;
    }
  }
  int ans = 0;
  for(int i = 0 ; i < n ; i++)
    for(int j = 0 ; j < m ; j++)
      ans = max(ans, h[i][j] + v[i][j] - 1);
  cout << ans << endl;
  return 0;
}
