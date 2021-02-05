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

const int N = 1e5 + 5;

char s[N], p[N];

int solve(vector<int>& a) {
  int r = 0;
  for(int i = 0; i < sz(a); i++) {
    if(!a[i]) continue;
    int j = i;
    while(j < sz(a) && a[j]) {
      j++;
    }
    r++;
    i = j - 1;
  }
  return r;
}

void solve() {
  scanf("%s", s);
  scanf("%s", p);
  vector<int> a, b;
  for(int i = 0; s[i]; i++) {
    if(i & 1) b.pb(s[i] != p[i]);
    else a.pb(s[i] != p[i]);
  }
  printf("%d\n", solve(a) + solve(b));
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
