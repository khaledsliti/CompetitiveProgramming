// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
typedef long long ll;

const int N = 1e5 + 5;

int n, l, r;
int a[N], ord[N];
int b[N];

int main()
{
  scanf("%d%d%d", &n, &l, &r);
  for(int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  for(int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    ord[--x] = i;
  }
  b[ord[0]] = l;
  for(int i = 1; i < n; i++) {
    b[ord[i]] = max(b[ord[i - 1]] - a[ord[i - 1]] + a[ord[i]] + 1, l);
    if(b[ord[i]] > r) {
      puts("-1");
      return 0;
    }
  }
  for(int i = 0; i < n; i++)
    printf("%d%c", b[i], " \n"[i == n - 1]);
  return 0;
}
