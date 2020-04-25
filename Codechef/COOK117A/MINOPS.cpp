// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 1e6 + 5;

int n;
char s[N], r[N];

long long solve() {
  scanf("%s%s", s, r);
  n = strlen(s);
  vector<int> v;
  for(int i = 0 ; i < n ; i++) {
    if(s[i] != r[i])
      v.pb(i);
  }
  if(!sz(v)) return 0;
  if(sz(v) == 1) return 1;
  int rep = v[sz(v) - 1] - v[0] + 1;
  int op = 1;
  long long best = 1LL * rep * op;
  for(int i = 0 ; i + 1 < sz(v) ; i++)
    v[i] = v[i + 1] - v[i] - 1;
  v.pop_back();
  sort(all(v));
  for(int i = sz(v) - 1 ; i >= 0 ; i--) {
    rep -= v[i];
    op++;
    best = min(best, 1LL * rep * op);
  }
  return best;
}

int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
    printf("%lld\n", solve());
  return 0;
}
