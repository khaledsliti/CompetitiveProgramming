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
int par[N], mn[N], mx[N];

int fs(int x) {
  return x == par[x] ? x : par[x] = fs(par[x]);
}

int main()
{
  int m;
  scanf("%d%d", &n, &m);
  for(int i = 0; i < n; i++) {
    mn[i] = mx[i] = i;
    par[i] = i;
  }
  while(m--) {
    int a, b;
    scanf("%d%d", &a, &b);
    --a, --b;
    a = fs(a), b = fs(b);
    if(a != b) {
      par[b] = a;
      mn[a] = min(mn[a], mn[b]);
      mx[a] = max(mx[a], mx[b]);
    }
  }
  vector<pair<int, int>> s;
  for(int i = 0; i < n; i++)
    if(fs(i) == i) {
      s.push_back({mn[i], mx[i]});
    }
  sort(all(s));
  int ans = 0;
  for(int i = 0; i < sz(s); i++) {
    int r = s[i].second;
    int j = i;
    while(j < sz(s) && r >= s[j].first) {
      r = max(r, s[j].second);
      j++;
    }
    ans += j - i - 1;
    i = j - 1;
  }
  cout <<  ans << endl;
  return 0;
}
