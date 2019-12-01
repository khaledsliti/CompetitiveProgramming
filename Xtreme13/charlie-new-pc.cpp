#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const long long oo = 1e12;
const int N = 11, K = 101;

int b, n;
int k[N];
int cost[N][K];

long long solve(int mask, int last, long long sum)
{
  if(mask + 1 == (1 << n))
    return sum;
  long long res = -1e12;
  for(int i = 0 ; i < n ; i++){
    if(!(mask & (1 << i))){
      
    }
  }
  return res;
}

int main()
{
  int T;
  cin >> T;
  while(T--){
    cin >> b >> n;
    for(int i = 0 ; i < n ; i++)
      cin >> k[i];
    long long sum_min = 0;
    for(int i = 0 ; i < n ; i++){
      for(int j = 0 ; j < k[i] ; j++)
        cin >> cost[i][j];
      sort(cost[i], cost[i] + k[i]);
      sum_min += cost[i][0];
    }
    long long ans = solve(0, 0, 0);
    if(ans < 0)
      ans = 0;
    cout << ans << endl;
  }
  return 0;
}
