// Guess Who's Back
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

const int N = 4e5 + 5;
const int Mod = 1e9 + 7;

int n;
int a[N], b[N];
int par[N], cnt;

int fs(int x) { return par[x] == x ? x : par[x] = fs(par[x]); }

void un(int a, int b) {
  a = fs(a), b = fs(b);
  if(a != b) {
    par[a] = b;
    cnt--;
  }
}

void solve() {
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    par[i] = i;
  }
  cnt = n;
  for(int i = 0; i < n; i++) {
    scanf("%d", a + i);
    a[i]--;
  }
  for(int i = 0; i < n; i++) {
    scanf("%d", b + i);
    b[i]--;
    un(a[i], b[i]);
  }
  int ans = 1;
  while(cnt-- > 0) {
    ans = ans * 2LL % Mod;
  }
  printf("%d\n", ans);
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
