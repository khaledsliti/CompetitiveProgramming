// We only fail when we stop trying
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

const int N = 2e5 + 5;

int n;
int a[N];

int main()
{
  int T;
  scanf("%d", &T);
  while(T--) {
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
      scanf("%d", a + i);
    sort(a, a + n);
    int q;
    scanf("%d", &q);
    while(q--) {
      int x, y;
      scanf("%d%d", &x, &y);
      int idx = lower_bound(a, a + n, x + y) - a;
      if(idx < n && a[idx] == x + y) printf("-1\n");
      else printf("%d\n", idx);
    }
  }
  return 0;
}
