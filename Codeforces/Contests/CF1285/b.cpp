#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define endl '\n'

const int N = 1e5 + 5;

int n;
int arr[N];

int main()
{
  int T;
  scanf("%d", &T);
  while(T--){
    scanf("%d", &n);
    long long sum = 0;
    for(int i = 0 ; i < n ; i++){
      scanf("%d", arr + i);
      sum += arr[i];
    }
    long long best = -2e9, cur = 0;
    for(int i = 0 ; i < n - 1 ; i++){
      cur += arr[i];
      best = max(best, cur);
      if(cur < 0) cur = 0;
    }
    cur = 0;
    for(int i = 1 ; i < n ; i++){
      cur += arr[i];
      best = max(best, cur);
      if(cur < 0) cur = 0;
    }
    if(best < sum) puts("Yes");
    else puts("No");
  }
  return 0;
}
