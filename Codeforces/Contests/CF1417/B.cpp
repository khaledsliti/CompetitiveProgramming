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

const int N = 3e5 + 5;

int n;
int ans[N];
vector<int> pos[N];

void solve() {
  scanf("%d", &n);
  for(int i = 1; i <= n; i++) {
    pos[i].clear();
    pos[i].push_back(0);
    ans[i] = n + 1;
  }
  for(int i = 1; i <= n; i++) {
    int a; scanf("%d", &a);
    pos[a].push_back(i);
  }
  for(int i = 1; i <= n; i++) {
    pos[i].push_back(n + 1);
  }
  for(int i = 1; i <= n; i++) {
    int mx_len = 0;
    for(int j = 0; j + 1 < sz(pos[i]); j++) {
      int a = pos[i][j];
      int b = pos[i][j + 1];
      mx_len = max(mx_len, b - a);
    }
    if(mx_len <= n) {
      ans[mx_len] = min(ans[mx_len], i);
    }
  }
  for(int i = 2; i <= n; i++) {
    ans[i] = min(ans[i], ans[i - 1]);
  }
  for(int i = 1; i <= n; i++) {
    if(ans[i] > n) ans[i] = -1;
    printf("%d ", ans[i]);
  }
  printf("\n");
}

int main()
{
  int T;
  scanf("%d", &T);
  while(T--) {
    solve();
  }
  return 0;
}
