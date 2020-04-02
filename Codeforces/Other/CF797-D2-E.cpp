// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 100006;
const int SQR = 317;

int n, q;
int arr[N];
int dp[N][SQR];

int main()
{
  scanf("%d", &n);
  for(int i = 1 ; i <= n ; i++)
    scanf("%d", arr + i);
  for(int i = n ; i > 0 ; i--) {
    for(int k = 1 ; k < SQR ; k++) {
      int nxt = i + arr[i] + k;
      if(nxt > n) dp[i][k] = 1;
      else dp[i][k] = 1 + dp[nxt][k];
    }
  }
  scanf("%d", &q);
  while(q--) {
    int p, k;
    scanf("%d%d", &p, &k);
    if(k < SQR) printf("%d\n", dp[p][k]);
    else {
      int cnt = 0;
      while(p <= n) {
        cnt++;
        p += arr[p] + k;
      }
      printf("%d\n", cnt);
    }
  }
  return 0;
}
