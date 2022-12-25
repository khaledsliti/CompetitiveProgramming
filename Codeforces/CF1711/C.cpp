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

int k;
int a[N];

bool solve(int n, int m) {
  bool have = false;
  for(int i = 0; i < k && m > 0; i++) {
    int can = a[i] / n;
    if(can < 2) continue;
    if(m == 1 && !have) {
      return false;
    }
    int take = min(m, can);
    m -= take;
    have = have || take > 2;
  }
  return m == 0;
}

void solve() {
  int n, m;
  cin >> n >> m >> k;
  for(int i = 0; i < k; i++) {
    cin >> a[i];
  }
  sort(a, a + k);
  reverse(a, a + k);
  if(solve(n, m) || solve(m, n)) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
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
