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

const int N = 50000 + 5;

int n;
vector<vector<int>> a;

void Solve() {
  cin >> n;
  a.clear();
  a.resize(n);
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    while(k--) {
      int x; cin >> x;
      a[i].push_back(x);
    }
  }

  set<int> seen;
  vector<int> sol;
  for (int i = n - 1; i >= 0; i--) {
    int w = -1;
    for (auto x: a[i]) {
      if (seen.find(x) == seen.end()) {
        w = x;
        break;
      }
    }
    if (w == -1) {
      cout << "-1" << endl;
      return;
    }
    sol.push_back(w);
    for (auto x: a[i]) {
      seen.insert(x);
    }
  }
  reverse(all(sol));
  for (int i = 0; i < n; i++) {
    cout << sol[i] << " ";
  }
  cout << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int T;
  cin >> T;
  while(T--) {
    Solve();
  }
  return 0;
}
