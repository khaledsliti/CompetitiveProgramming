#pragma GCC target("popcnt")

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

const int N = 5e4 + 2;

int n, m;
vector<int> g[N];
bitset<N> ans[N];
int in[N];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m;
  while(m--) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    g[b].push_back(a);
    in[a]++;
  }
  queue<int> q;
  for(int i = 0; i < n; i++) {
    ans[i].set(i);
    if(in[i] == 0) {
      q.push(i);
    }
  }

  while(q.size()) {
    int u = q.front();
    q.pop();
    for(int v: g[u]) {
      ans[v] |= ans[u];
      in[v]--;
      if(in[v] == 0) {
        q.push(v);
      }
    }
  }

  for(int i = 0; i < n; i++) {
    cout << ans[i].count() << " ";
  }
  cout << endl;

  return 0;
}
