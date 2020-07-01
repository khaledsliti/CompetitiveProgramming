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

const int N = 5001;

int n;
int par[N];

int fs(int x) {
  return par[x] == x ? par[x] : par[x] = fs(par[x]);
}

void solve() {
  int q;
  scanf("%d%d", &n, &q);
  for(int i = 0; i < n; i++) {
    par[i] = i;
  }
  int ans = n;
  while(q--) {
    int l, r;
    scanf("%d%d", &l, &r);
    --l, --r;
    while(l < r) {
      int a = fs(l), b = fs(r);
      if(a != b) {
        par[a] = b;
        ans--;
      }
      l++, r--;
    }
    printf("%d\n", ans);
  }
}

int main()
{
  solve();
  return 0;
}
