#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

int po(int a, int b)
{
  if(!b)
    return 1;
  int r = po(a, b >> 1);
  r *= r;
  if(b & 1)
    r *= a;
  return r;
}

void solve(int a)
{
  if(a == 1){
    printf("0\n");
    return;
  }
  int n = a;
  vector<int> pr;
  for(int i = 2 ; i * i <= n ; i++)
    if(n % i == 0){
      pr.pb(i);
      while(n % i == 0)
        n /= i;
    }
  if(n > 1)
    pr.pb(n);
  int res = a;
  for(auto p : pr){
    res /= p;
    res *= p - 1;
  }
  printf("%d\n", res);
}

int main()
{
  int n;
  while(scanf("%d", &n) && n)
    solve(n);
  return 0;
}
