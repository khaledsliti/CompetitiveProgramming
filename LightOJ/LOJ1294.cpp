#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

int main()
{
  int T, tc = 1;
  scanf("%d", &T);
  while(T--){
    int n, m;
    scanf("%d%d", &n, &m);
    printf("Case %d: %lld\n", tc++, 1LL * n * m / 2LL);
  }
  return 0;
}
