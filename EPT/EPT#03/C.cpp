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

const int N = 1e5 + 5;

int n;
int par[N];

int find(int x) { return par[x] == x ? x : par[x] = find(par[x]); }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  for (int i = 0; i < n; i++) {
    par[i] = i;
  }
  vector<pair<int, int>> del;
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    int pa = find(a), pb = find(b);
    if (pa == pb) {
      del.push_back({a, b});
      continue;
    }
    par[pa] = pb;
  }

  vector<int> v;
  for (int i = 0; i < n; i++) {
    if (find(i) == i) {
      v.push_back(i);
    }
  }

  cout << sz(del) << endl;
  for (int i = 0; i < sz(v) - 1; i++) {
    cout << del[i].first + 1 << " " << del[i].second + 1 << " ";
    cout << v[i] + 1 << " " << v[i + 1] + 1 << endl;
  }

  return 0;
}
