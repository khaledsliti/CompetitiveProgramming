#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

long long profit(long long n, long long c, long long t)
{
  return t * (c - n * t);
}

int f(long long n, long long c)
{
  if(n == 0) return 0;
  long long t1 = (c + 2 * n - 1) / (2 * n);
  long long t2 = c / (2 * n);
  if(profit(n, c, t1) > profit(n, c, t2))
    return t1;
  return t2;
}

int main()
{
  int T, tc = 1;
  scanf("%d", &T);
  while(T--){
    int n, c;
    scanf("%d%d", &n, &c);
    printf("Case %d: %d\n", tc++, f(n, c));
  }
  return 0;
}
