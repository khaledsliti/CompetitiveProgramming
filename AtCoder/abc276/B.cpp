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



int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, m;
  cin >> n >> m;
  vector<set<int>> g(n);
  while(m--) {
    int a, b; cin >> a >> b;
    --a, --b;
    g[a].insert(b);
    g[b].insert(a);
  }
  for(int i = 0; i < n; i++) {
    cout << sz(g[i]);
    for(int x: g[i]) {
      cout << " " << x + 1;
    }
    cout << endl;
  }
  return 0;
}
