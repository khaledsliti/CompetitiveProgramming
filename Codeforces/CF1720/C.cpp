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

int n, m;
string g[N];

bool in(int i, int j) {
  return i >= 0 && i < n && j >= 0 && j < m;
}

bool zero(int i, int j) {
  return in(i, j) && g[i][j] == '0';
}

void solve() {
  cin >> n >> m;
  int ones = 0;
  for(int i = 0; i < n; i++) {
    cin >> g[i];
    for(int j = 0; j < m; j++) {
      ones += g[i][j] == '1';
    }
  }
  if(ones == n * m) {
    cout << ones - 2 << endl;
    return;
  }
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(zero(i, j) && (zero(i + 1, j) || zero(i, j + 1) || zero(i + 1, j + 1) || zero(i + 1, j - 1))) {
        cout << ones << endl;
        return;
      }
    }
  }
  cout << ones - 1 << endl;
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
