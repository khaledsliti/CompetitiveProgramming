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

const int N = 2e3 + 5;

struct Graph {
  int n, idx;
  vector<vector<int>> dp;
  vector<vector<int>> g;
  Graph(int _n): n(_n) {
    g.resize(n);
    dp.resize(n, vector<int>(2001, -1));
  }
  void addEdge(int a, int b) {
    g[a].push_back(b);
  }
  int solve(int cur, int steps) {
    if(steps == 0) return cur == n - 1;
    int& r = dp[cur][steps];
    if(r != -1) return r;
    r = 0;
    for(int nxt: g[cur]) {
      r = r || solve(nxt, steps - 1);
    }
    return r;
  }
};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n1, n2, m1, m2;
  cin >> n1 >> n2 >> m1 >> m2;
  Graph g1(n1), g2(n2);
  while(m1--) {
    int a, b;
    cin >> a >> b;
    g1.addEdge(--a, --b);
  }
  while(m2--) {
    int a, b;
    cin >> a >> b;
    g2.addEdge(--a, --b);
  }


  int q;
  cin >> q;
  while(q--) {
    int cnt;
    cin >> cnt;
    bool yes = false;
    for(int i = 0; i <= cnt; i++) {
      if(g1.solve(0, i) && g2.solve(0, cnt - i)) {
        yes = true;
      }
    }
    if(yes) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
  return 0;
}
