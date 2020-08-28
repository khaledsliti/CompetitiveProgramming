#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 2e5 + 5;

int n, arr[N];

int main()
{
  int T;
  scanf("%d", &T);
  while(T--){
    scanf("%d", &n);
    int mn = 2e9, mx = -1;
    bool found = false;
    for(int i = 0 ; i < n ; i++){
      scanf("%d", arr + i);
      if(arr[i] > -1)
        found = true;
    }
    if(!found){
      printf("0 0\n");
    }else{
      for(int i = 0 ; i < n ; i++){
        if(i > 0 && arr[i] != -1 && arr[i - 1] == -1){
          mx = max(mx, arr[i]);
          mn = min(mn, arr[i]);
        }
        if(i + 1 < n && arr[i] != -1 && arr[i + 1] == -1) {
          mx = max(mx, arr[i]);
          mn = min(mn, arr[i]);
        }
      }
      int mid = (mn + mx) / 2;
      for(int i = 0 ; i < n ; i++){
        if(arr[i] == -1)
          arr[i] = mid;
      }
      int sol = abs(arr[0] - arr[1]);
      for(int i = 0 ; i < n - 1 ; i++)
        sol = max(sol, abs(arr[i] - arr[i + 1]));
      printf("%d %d\n", sol, mid);
    }
  }
  return 0;
}

//Check array sizes
//Check limits: N = 1 ? N = Max ? .. etc
//Check time complexity