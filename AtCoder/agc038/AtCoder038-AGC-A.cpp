#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 1e3 + 5;

int n, m, a, b;
int row[N], col[N];
int ans[N][N];

void solve(int r, int c)
{
  if(r < 0 || r > n || c < 0 || c > m)
    return;
  // cout << n << " " << m << " " << r << " " << c << endl;
  for(int i = 0 ; i < n ; i++){
    if(i < r)
      row[i] = a;
    else
      row[i] = m - a;
  }
  for(int i = 0 ; i < m ; i++)
    if(i < c)
      col[i] = b;
    else
      col[i] = n - b;
  // for(int i = 0 ; i < n ; i++)
  //   cout << row[i] << " ";
  // cout << endl;
  // for(int i = 0 ; i < m ; i++)
  //   cout << col[i] << " ";
  // cout << endl;
  memset(ans, 0, sizeof ans);
  for(int i = 0 ; i < n ; i++){
    for(int j = 0 ; j < m && row[i]; j++)
      if(col[j])
        col[j]--, row[i]--, ans[i][j] = 1;
  }
  for(int i = 0 ; i < n ; i++){
    for(int j = 0 ; j < m ; j++)
      printf("%d", ans[i][j]);
    printf("\n");
  }
  exit(0);
}

int main()
{
  cin >> n >> m >> a >> b;
  for(int r = 0 ; r <= n ; r++){
    int right = r * (m - 2 * a) + n * a - m * b;
    int left = n - 2 * b;
    // cout << right << " " << left << " " << r << endl;
    if(left == 0){
      if(right == 0)
        solve(r, 0);
    }else{
      if(right % left == 0)
        solve(r, right / left);
    }
  }
  printf("-1\n");
  return 0;
}
