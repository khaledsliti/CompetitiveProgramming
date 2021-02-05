// RedStone
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;

int main()
{
  int T;
  scanf("%d", &T);
  while(T--) {
    int n, m;
    scanf("%d%d", &n, &m);
    int l = 1, h = n, best = 0;
    while(l <= h) {
      int mid = (l + h) / 2;
      if(mid * 1LL * (mid - 1) / 2 <= m) {
        best = mid;
        l = mid + 1;
      } else {
        h = mid - 1;
      }
    }
    printf("%d\n", best);
  }
  return 0;
}
