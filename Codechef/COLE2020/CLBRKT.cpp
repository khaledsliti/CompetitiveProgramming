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

const int N = 1e7 + 2;

int n;
char s[N];
int p[N], nxt[N], to[N];
int last[N + N];

void solve() {
  scanf("%s", s);
  n = strlen(s);
  int cur = 0;
  for(int i = 0; i < n; i++) {
    p[i] = (s[i] == '(') - (s[i] == ')');
    if(i) p[i] += p[i - 1];
  }
  nxt[n] = n;
  for(int i = 0; i <= 2 * n; i++)
    last[i] = -1;
  for(int i = n - 1; i >= 0; i--) {
    if(s[i] == '(') nxt[i] = i;
    else nxt[i] = nxt[i + 1];
    if(last[n + p[i] - 1] != -1) to[i] = last[n + p[i] - 1];
    else to[i] = n;
    last[n + p[i]] = i;
  }
  int q;
  scanf("%d", &q);
  while(q--) {
    int idx;
    scanf("%d", &idx);
    --idx;
    idx = nxt[idx];
    if(idx >= n) puts("-1");
    else {
      idx = to[idx];
      if(idx >= n) puts("-1");
      else printf("%d\n", idx + 1);
    }
  }
}

int main()
{
  int T;
  scanf("%d", &T);
  while(T--)
    solve();
  return 0;
}
