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

const int N = 2e5 + 5;

int n, m;
int par[N], siz[N];

int fs(int x) {
  return par[x] == x ? x : par[x] = fs(par[x]);
}

int main()
{
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    par[i] = i, siz[i] = 1;
  }
  int cnt = n, best = 1;
  for(int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    a = fs(a), b = fs(b);
    if(a != b) {
      cnt--;
      par[a] = b;
      siz[b] += siz[a];
      best = max(best, siz[b]);
    }
    cout << cnt << " " << best << endl;
  }
  return 0;
}
