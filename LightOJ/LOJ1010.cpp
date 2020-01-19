#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

int solve(int a, int b)
{
  if(a > b) swap(a, b);
  if(a == 1) return b;
  if(a == 2) return ((b >> 2) << 2) + (min(2, b & 3) << 1);
  return (a >> 1) * (b >> 1) + (a + 1 >> 1) * (b + 1 >> 1);
}

int main()
{
  int T, tc = 1;
  scanf("%d", &T);
  while(T--){
    int a, b;
    scanf("%d%d", &a, &b);
    printf("Case %d: %d\n", tc++, solve(a, b));
  }
  return 0;
}
