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

const int N = 1e6 + 3;

int n, m;
vector<vector<int>> arr;
int diff[N];

void solve() {
  cin >> n >> m;
  arr.clear();
  arr.resize(n, vector<int>(m));
  int s = 0;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      cin >> arr[i][j];
      s += arr[i][j];
    }
  }
  if(s % n != 0) {
    cout << -1 << endl;
    return;
  }
  s /= n;
  for(int i = 0; i < n; i++) {
    diff[i] = -s;
    for(int j = 0; j < m; j++) {
      diff[i] += arr[i][j];
    }
  }

  // for(int i = 0; i < n; i++) {
  //   cout << diff[i] << endl;
  // }

  vector<array<int, 3>> sol;
  for(int j = 0; j < m; j++) {
    vector<int> a, b;
    for(int i = 0; i < n; i++) {
      if(arr[i][j] == 1 && diff[i] > 0) {
        a.push_back(i);
      }
      if(arr[i][j] == 0 && diff[i] < 0) {
        b.push_back(i);
      }
    }
    int mn = min(sz(a), sz(b));
    for(int k = 0; k < mn; k++) {
      int idx_1 = a[k];
      int idx_0 = b[k];
      diff[idx_1]--;
      diff[idx_0]++;
      sol.push_back({idx_1, idx_0, j});
    }
  }

  cout << sz(sol) << endl;
  for(auto& x : sol) {
    for(int y : x) {
      cout << y + 1 << " ";
    }
    cout << endl;
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
