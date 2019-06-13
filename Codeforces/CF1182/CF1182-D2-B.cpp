#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 505;

int n, m;
string s[N];
int arr[N][N];
int U[N][N], D[N][N], L[N][N], R[N][N];

int main()
{
  ios::sync_with_stdio(false);
  cin >> n >> m;
  int sum = 0;
  for(int i = 0 ; i < n ; i++){
    cin >> s[i];
    for(int j = 0 ; j < m ; j++){
      arr[i][j] = s[i][j] == '*';
      sum += s[i][j] == '*';
    }
  }
  for(int i = 0 ; i < n ; i++){
    L[i][0] = 1;
    for(int j = 1 ; j < m ; j++){
      L[i][j] = 1 + (arr[i][j] == arr[i][j - 1]) * L[i][j - 1];
    }
    R[i][m - 1] = 1;
    for(int j = m - 2 ; j >= 0 ; j--)
      R[i][j] = 1 + (arr[i][j] == arr[i][j + 1]) * R[i][j + 1];
  }
  for(int j = 0 ; j < m ; j++){
    U[0][j] = 1;
    for(int i = 1 ; i < n ; i++)
      U[i][j] = 1 + (arr[i][j] == arr[i - 1][j]) * U[i - 1][j];
    D[n - 1][j] = 1;
    for(int i = n - 2 ; i >= 0 ; i--)
      D[i][j] = 1 + (arr[i][j] == arr[i + 1][j]) * D[i + 1][j];
  }
  bool yes = false;
  for(int i = 1 ; i < n - 1 && !yes ; i++){
    for(int j = 1 ; j < m - 1 && !yes ; j++){
      if(arr[i][j] && arr[i - 1][j] && arr[i][j + 1] && arr[i + 1][j] && arr[i][j - 1] &&
        !arr[i - 1][j - 1] && !arr[i + 1][j - 1] && !arr[i + 1][j + 1] && !arr[i - 1][j + 1] &&
        min(U[i - 1][j - 1], U[i - 1][j + 1]) >= U[i - 1][j] &&
        min(D[i + 1][j - 1], D[i + 1][j + 1]) >= D[i + 1][j] &&
        min(R[i - 1][j + 1], R[i + 1][j + 1]) >= R[i][j + 1] &&
        min(L[i - 1][j - 1], L[i + 1][j - 1]) >= L[i][j - 1] &&
        sum == U[i - 1][j] + D[i + 1][j] + R[i][j + 1] + L[i][j - 1] + 1)
        yes = true;
    }
  }
  if(yes)
    puts("YES");
  else
    puts("NO");
  return 0;
}
