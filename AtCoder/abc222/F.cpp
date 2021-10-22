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

const int N = 2e5 + 5, E = 4e5 + 5;

int n, m, k, e;
int head[N], to[E], nxt[E], fr[E], cost[E];
int d[N];
long long mxSub[N];
map<int, map<int, long long>> mxSubExcept;
long long ans[N], solPar[N];

void init() {
  e = 0;
  memset(head, -1, sizeof head);
}

void addEdge(int f, int t, int c) {
  nxt[e] = head[f];
  head[f] = e;
  to[e] = t;
  fr[e] = f;
  cost[e] = c;
  e++;
}

void dfs(int u, int p) {
  vector<int> ch;
  vector<long long> costCh;
  for(int k = head[u]; ~k; k = nxt[k]) {
    int v = to[k];
    long long cur = 0;
    if(v != p) {
      dfs(v, u);
      cur = max(cur, cost[k] + mxSub[v]);
      cur = max(cur, (ll)cost[k] + d[v]);
    }
    ch.push_back(v);
    costCh.push_back(cur);
    mxSub[u] = max(mxSub[u], cur);
  }
  if(sz(ch)) {
    vector<long long> left(ch.size()), right(ch.size());
    for(int i = 0; i < sz(ch); i++) {
      left[i] = costCh[i];
      if(i > 0) {
        left[i] = max(left[i - 1], left[i]);
      }
    }
    for(int i = sz(ch) - 1; i >= 0; i--) {
      right[i] = costCh[i];
      if(i + 1 < sz(ch)) {
        right[i] = max(right[i + 1], right[i]);
      }
    }
    for(int i = 0; i < sz(ch); i++) {
      int v = ch[i];
      mxSubExcept[u][v] = 0;
      if(i > 0) {
        mxSubExcept[u][v] = max(mxSubExcept[u][v], left[i - 1]);
      }
      if(i < sz(ch) - 1) {
        mxSubExcept[u][v] = max(mxSubExcept[u][v], right[i + 1]);
      }
    }
  }
}

void solve(int u, int edgeToPar) {
  // to children
  ans[u] = mxSub[u];
  // to parent
  if(edgeToPar != -1) {
    int p = to[edgeToPar];
    long long c = cost[edgeToPar];
    solPar[u] = c + d[p]; // stop in the par
    solPar[u] = max(solPar[u], c + mxSubExcept[p][u]); // go down
    solPar[u] = max(solPar[u], c + solPar[p]); // go up
    ans[u] = max(ans[u], solPar[u]);
  }
  for(int k = head[u]; ~k; k = nxt[k]) {
    int v = to[k];
    if(k != edgeToPar) {
      solve(v, k ^ 1);
    }
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  init();
  for(int i = 0; i < n - 1; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    --a, --b;
    addEdge(a, b, c);
    addEdge(b, a, c);
  }
  for(int i = 0; i < n; i++) {
    cin >> d[i];
  }
  dfs(0, -1);
  solve(0, -1);

  for(int i = 0; i < n; i++) {
    cout << ans[i] << endl;
  }
  return 0;
}
