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
const int L = 30;

typedef pair<vector<int>, vector<int>> group;

int n;

bool tryCut(const group& g, int bit, vector<group>& out) {
  if(!sz(g.first)) {
    return true;
  }
  int n = sz(g.first);
  vector<int> a0, a1, b0, b1;
  for(int a: g.first) {
    if((a >> bit) & 1) {
      a1.push_back(a);
    } else {
      a0.push_back(a);
    }
  }
  for(int b: g.second) {
    if((b >> bit) & 1) {
      b1.push_back(b);
    } else {
      b0.push_back(b);
    }
  }
  if(sz(a0) != sz(b1)) {
    return false;
  }
  out.push_back({a0, b1});
  out.push_back({a1, b0});
  return true;
}

void solve() {
  cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> b(n);
  for(int i = 0; i <n ; i++) {
    cin >> b[i];
  }
  vector<group> groups;
  groups.push_back(mp(a, b));
  int so_far = 0;
  for(int b = L; b >= 0; b--) {
    bool all_ok = true;
    vector<group> tmp;
    for(auto g : groups) {
      vector<group> cur;
      if (!tryCut(g, b, cur)) {
        all_ok = false;
        break;
      } else {
        tmp.insert(tmp.end(), cur.begin(), cur.end());
      }
    }
    if(all_ok) {
      so_far |= (1 << b);
      swap(tmp, groups);
    }
  }
  cout << so_far << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int T;
  cin >> T;
  while(T--) {
    solve();
  }
  return 0;
}
