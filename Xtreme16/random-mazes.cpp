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

const int N = 504;

int n, w;
string dir = "NEWS";
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, 1, -1, 0};
int loop[N * N];

struct DSU {
  vector<int> par;
  void init(int n) {
    par.clear();
    par.resize(n);
    iota(par.begin(), par.end(), 0);
  }
  int find(int x) {
    return x == par[x] ? x : par[x] = find(par[x]);
  }
  bool unite(int x, int y) {
    x = find(x);
    y = find(y);
    if(x != y) {
      par[x] = y;
      loop[y] |= loop[x];
      return true;
    }
    loop[y] = 1;
    return false;
  }
} ds;

int get(int x, int y) {
  return x * n + y;
}

bool isM(int a, int b) {
  int c = 0, m = get(0, n - 1);
  for(int it = 0; it < 2; it++) {
    if(ds.find(a) == ds.find(0) && ds.find(b) == ds.find(m)) {
      return true;
    }
    swap(a, b);
  }
  return false;
}

bool isL(int a, int b) {
  if(ds.find(a) == ds.find(b) && ds.find(a) == ds.find(0)) {
    return true;
  }
  for(int it = 0; it < 2; it++) {
    if(loop[ds.find(a)] && ds.find(b) == ds.find(0)) {
      return true;
    }
    swap(a, b);
  }
  return false;
}

bool isT(int a, int b) {
  int c = 0, t = get(n - 1, n - 1);
  for(int it = 0; it < 2; it++) {
    if(ds.find(a) == ds.find(0) && ds.find(b) == ds.find(t)) {
      return true;
    }
    swap(a, b);
  }
  return false;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> w;
  ds.init(n * n);
  int pr = 1;
  bool doneT = false;
  while(w--) {
    // cout << "Proposal " << pr++ << endl;
    // for(int i = 0; i < n; i++) {
    //   for(int j = 0; j < n; j++) {
    //     cout << ds.find(get(i, j)) << "\t";
    //   }
    //   cout << endl;
    // }
    // for(int i = 0; i < n * n; i++) {
    //   cout << "(" << i << ":" << loop[i] << ") ";
    // }
    // cout << endl;
    int x, y;
    char d;
    cin >> x >> y >> d;
    int idx_dir;
    for(int i = 0; i < 4; i++) {
      if(dir[i] == d) {
        idx_dir = i;
      }
    }
    int a = get(x, y);
    int b = get(x + dx[idx_dir], y + dy[idx_dir]);
    if(isM(a, b)) {
      cout << "M" << endl;
      continue;
    }
    if(isL(a, b)) {
      cout << "L" << endl;
      continue;
    }
    if(isT(a, b) || doneT) {
      cout << "T" << endl;
      doneT = true;
    } else {
      cout << "K" << endl;
    }
    ds.unite(a, b);
  }
  return 0;
}
