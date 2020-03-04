#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 1e5 + 5;

long long n;
int m;
int cnt[64];

int log(long long x)
{
  if(x == 1)
    return 0;
  return 1 + log(x >> 1);
}

int solve()
{
  int ans = 0;
  for(int i = 0 ; i < 63 ; i++){
    if((n >> i) & 1){
      bool found = false;
      for(int j = i ; j < 63 ; j++){
        if(cnt[j]){
          cnt[j]--;
          for(int k = i + 1 ; k < j ; k++)
            cnt[k]++;
          found = true;
          ans += j - i;
          break;
        }
      }
      if(!found) return  -1;
    }
    cnt[i + 1] += cnt[i] / 2;
  }
  return ans;
}

int main()
{
  int t;
  scanf("%d", &t);
  while(t--){
    scanf("%I64d%d", &n, &m);
    memset(cnt, 0, sizeof cnt);
    for(int it =  0 ; it < m ; it++){
      long long a;
      scanf("%I64d", &a);
      cnt[log(a)]++;
    }
    printf("%d\n", solve());
  }
  return 0;
}
