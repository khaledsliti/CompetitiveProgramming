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

const int N = 1000;

int n, m;
int par[N];

int find(int a) {
  return par[a] == a ? a : par[a] = find(par[a]);
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    par[i] = i;
  }
  int ans = n;
  while(m--) {
    int u, v;
    cin >> u >> v;
    u = find(--u);
    v = find(--v);
    if (u != v) {
      ans--;
      par[u] = v;
    }
  }
  cout << ans << endl;
  return 0;
}
