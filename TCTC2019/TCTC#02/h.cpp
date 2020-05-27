#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) begin(x), end(x)

const int N = 1005;
const int K = 1e6 + 5;

int n, m, k;
int arr[N][N];
int occ[K];

int main()
{
  scanf("%d%d%d", &n, &m, &k);
  for(int i = 0 ; i < n ; i++){
    for(int j = 0 ; j < m ; j++){
      scanf("%d", &arr[i][j]);
      arr[i][j]--;
    }
  }
  for(int i = 0 ; i < n ; i++){
    sort(arr[i], arr[i] + m);
    if(arr[i][0] == arr[i][m - 1])
      arr[i][m - 1] = -1;
    for(int j = 0 ; j < m ; j++){
      int l = j;
      while(l < m && arr[i][j] == arr[i][l])
        ++l;
      if(arr[i][j] > -1)
        occ[arr[i][j]] += l - j;
      j = l - 1;
    }
  }
  // for(int i = 0 ; i < n ; i++){
  //   for(int j = 0 ; j < m ; j++)
  //     cout << arr[i][j] << " ";
  //   cout << endl;
  // }
  sort(occ, occ + k);
  cout << n * m - occ[k - 1] - occ[k - 2] << endl;
  return 0;
}
