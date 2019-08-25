#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

int n;
int arr[N][N];

int main()
{
  int n;
  cin >> n;
  int cnt = 0;
  for(int i = 0 ; i < n ; i += 4){
    for(int j = 0 ; j < n ; j += 4){
      for(int k = 0 ; k < 4 ; k++)
        for(int l = 0 ; l < 4 ; l++)
          arr[i + k][j + l] = cnt++;
    }
  }
  for(int i = 0 ; i < n ; i++){
    for(int j = 0 ; j < n ; j++)
      printf("%d ",arr[i][j]);
    printf("\n");
  }
  return 0;
}