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

const int N = 1007;

int n, k;
int x[N], y[N];
int ok[N];

double dist(int i, int j) {
  return sqrt(1LL * (x[i] - x[j]) * (x[i] - x[j]) + 1LL * (y[i] - y[j]) * (y[i] - y[j]));
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> k;
  for(int i = 0; i < k; i++) {
    int a; cin >> a;
    ok[--a] = 1;
  }
  for(int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
  }
  double ans = 0;
  for(int i = 0; i < n; i++) {
    double cur = 1e9;
    for(int j = 0; j < n; j++) {
      if(ok[j]) {
        cur = min(cur, dist(i, j));
      }
    }
    ans = max(ans, cur);
  }
  cout << fixed << setprecision(10) << ans << endl;
  return 0;
}
