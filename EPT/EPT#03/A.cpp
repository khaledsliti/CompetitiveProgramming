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

const int N = 1e6 + 4;

int n;
int arr[N];
vector<int> g[N];
int par[N], siz[N];
int ok[N];

int find(int x) { return par[x] == x ? x : par[x] = find(par[x]); }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    g[a].push_back(b);
    swap(a, b);
    g[a].push_back(b);
  }

  vector<int> ord(n);
  for (int i = 0; i < n; i++) {
    ord[i] = i;
  }

  sort(all(ord), [&](int a, int b) { return arr[a] < arr[b]; });

  long long ans = 0;
  for (int f : {1, -1}) {
    for (int i = 0; i < n; i++) {
      par[i] = i;
      siz[i] = 1;
      ok[i] = 0;
    }
    for (int i = 0; i < n; i++) {
      int u = ord[i];
      vector<int> sizes;
      for (int v : g[u]) {
        if (!ok[v]) {
          continue;
        }
        int a = find(u), b = find(v);
        sizes.push_back(siz[b]);
        par[a] = b;
        siz[b] += siz[a];
      }
      int curr = 1;
      for (int s : sizes) {
        ans += 1LL * f * curr * s * arr[u];
        curr += s;
      }
      ok[u] = 1;
    }
    reverse(all(ord));
  }

  cout << ans << endl;
  return 0;
}
