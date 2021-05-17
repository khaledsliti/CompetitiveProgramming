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

const int N = 21, V = 1000;

int n;
int A, B;
int x[V];
int cur[V];

bool check(int sol) {
  for(int i = 0; i < V; i++) {
    cur[i] = 0;
  }
  cur[sol] = 1;
  for(int i = sol ; i > 0; i--) {
    if(x[i] > cur[i]) {
      return false;
    }
    int diff = cur[i] - x[i];
    if(i - A > 0) cur[i - A] += diff;
    if(i - B > 0) cur[i - B] += diff;
    cur[i] = x[i];
  }
  return true;
}

void solve() {
  cin >> n >> A >> B;
  for(int i = 0; i < V; i++) {
    x[i] = 0;
  }
  int mx = 0;
  for(int i = 1; i <= n; i++) {
    cin >> x[i];
    if(x[i]) mx = max(mx, i);
  }
  for(int sol = mx; sol <= V - 1; sol++) {
    if(check(sol)) {
      cout << sol << endl;
      return;
    }
  }
  cout << "IMPOSSIBLE" << endl;
}

int main()
{
  int T; cin >> T;
  for(int tc = 1; tc <= T; tc++) {
    cout << "Case #" << tc << ": ";
    solve();
  }
  return 0;
}
