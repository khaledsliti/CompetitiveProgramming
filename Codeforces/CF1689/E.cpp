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

const int N = 6007;

int n;
int arr[N];
vector<array<int, 3>> ar;
int par[N], cnt[N];

void addEdge(int a, int b, int c) {
  ar.push_back({c, a, b});
}

void solve() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  ar.clear();
  for(int i = 0; i < n; i++) {
    addEdge(i * 3 + 1, i * 3, 1);
    addEdge(i * 3 + 1, i * 3 + 2, 1);
  }
  for(int i = 0; i < n; i++) {
    for(int a: {-1, 0, 1}) {
      for(int j = 0; j < n; j++) {
        for(int b : {-1, 0, 1}) {
          int x = arr[i] + a;
          int y = arr[j] + b;
          if(x & y) {
            int u = i * 3 + a + 1;
            int v = j * 3 + b + 1;
            addEdge(u, v, 0);
          }
        }
      }
    }
  }
  for(int i = 0; i < 3 * n; i++) {
    par[i] = i;
    cnt[i] = i % 3 == 1;
  }
  sort(all(ar));
  int ans = 0;
  for(int i = 0; i < sz(ar); i++) {
    int cnt = 0;
  }
  cout << ans << endl;
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
