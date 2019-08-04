#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 2e6 + 5;

int n;
int arr[N];

int main()
{
  scanf("%d", &n);
  for(int i = 0 ; i < n ; i++){
    int a;
    scanf("%d", &a);
    arr[a] = a;
  }
  for(int i = 1 ; i < N ; i++){
    if(arr[i] == 0)
      arr[i] = arr[i - 1];
  }
  int ans = 0;
  for(int cur = 1 ; cur < N ; cur++){
    if(arr[cur] == cur)
      for(int j = cur ; j + cur - 1 < N ; j += cur){
        int v = arr[j + cur - 1];
        if(v > j && ans < v - j)
          ans = v - j;
      }
  }
  cout << ans << endl;
  return 0;
}
