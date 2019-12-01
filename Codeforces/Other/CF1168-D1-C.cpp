#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 3e5 + 9;
const int LOG = 19;

int n, q;
int a[N];
int nxt[N][LOG];
int last[LOG];
int dp[N][LOG];

int getNext(int cur, int bit)
{
  if(cur >= n)
    return cur;
  if(a[cur] & (1 << bit))
    return cur;
  int& r = dp[cur][bit];
  if(r != -1)
    return r;
  r = n;
  for(int b = 0 ; b < LOG ; b++){
    if(a[cur] & (1 << b)){
      r = min(r, getNext(nxt[cur][b], bit));
    }
  }
  return r;
}

int main()
{
  ios::sync_with_stdio(false);
  scanf("%d%d", &n, &q);
  for(int i = 0 ; i < n ; i++){
    scanf("%d", a + i);
  }
  for(int bit = 0 ; bit < LOG ; bit++)
    last[bit] = n;
  for(int i = n - 1 ; i >= 0 ; i--){
    int cur = a[i];
    for(int bit = 0 ; bit < LOG ; bit++){
      nxt[i][bit] = last[bit];
      if(cur & (1 << bit)){
        last[bit] = i;
      }
    }
  }
  memset(dp, -1, sizeof dp);
  while(q--){
    int x, y;
    scanf("%d%d", &x, &y);
    --x, --y;
    bool yes = false;
    for(int b = 0 ; b < LOG ; b++){
      if(a[y] & (1 << b) && getNext(x, b) <= y){
        yes = true;
        break;
      }
    }
    if(yes) puts("Shi");
    else puts("Fou");
  }
  return 0;
}
