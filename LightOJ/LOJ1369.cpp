#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 2e5 + 5;

int n, q;
int arr[N];

long long get(int idx)
{
  return 1LL * arr[idx] * (n - 2 * idx - 1);
}

int main()
{
  int ts;
  scanf("%d", &ts);
  for(int tc = 1 ; tc <= ts ; tc++){
    printf("Case %d:\n", tc);
    scanf("%d%d", &n, &q);
    long long ans = 0;
    for(int i = 0 ; i < n ; i++){
      scanf("%d", arr + i);
      ans += get(i);
    }
    while(q--){
      int t; scanf("%d", &t);
      if(t == 1) printf("%lld\n", ans);
      else{
        int idx, v;
        scanf("%d%d", &idx, &v);
        ans -= get(idx);
        arr[idx] = v;
        ans += get(idx);
      }
    }
  }
  return 0;
}
