// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 1e5 + 5;
const int Mod = 663224321;

int n;
int po[N];
int ans[N];

int main()
{
  po[0] = 1;
  for(int i = 1 ; i < N ; i++) {
    po[i] = (po[i - 1] * 2) % Mod;
  }
  ans[1] = 1;
  for(int i = 2 ; i < N ; i++) {
    ans[i] = (1LL * ans[i - 1] * (po[i - 1] - 1)) % Mod;
  }
  int q;
  scanf("%d", &q);
  while(q--) {
    int n; scanf("%d", &n);
    printf("%d\n", ans[n]);
  }
  return 0;
}
