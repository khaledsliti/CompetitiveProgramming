#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 150005;

int n;
int arr[N];

int main()
{
  int T;
  scanf("%d", &T);
  while(T--){
    scanf("%d", &n);
    for(int i = 0 ; i < n ; i++)
      scanf("%d", arr + i);
    int mn = 1e9;
    int ans = 0;
    for(int i = n - 1 ; i >= 0 ; i--){
      if(arr[i] > mn)
        ans++;
      mn = min(mn, arr[i]);
    }
    printf("%d\n", ans);
  }
  return 0;
}
