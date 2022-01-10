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

const int N = 2e5 + 5;

int n;
struct item {
  int idx, p, v;
};

item a[N];

void solve() {
  cin >> n;
  for(int i = 0; i < n ;i++) {
    int x; cin >> x;
    a[i].idx = i, a[i].p = x;
  }
  for(int i = 0; i < n; i++) {
    char c; cin >> c;
    a[i].v = c - '0';
  }
  sort(a, a + n, [&](item x, item y) {
    if(x.v != y.v) {
      return x.v < y.v;
    }
    return x.p < y.p;
  });
  vector<int> sol(n);
  for(int i = 0; i < n; i++) {
    sol[a[i].idx] = i;
  }
  for(int i = 0; i < n; i++) {
    cout << sol[i] + 1 << " ";
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
    solve();
  }
  return 0;
}
