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

const int N = 1e6;

int n, m;
vector<vector<int>> arr, tmp;

int check(int l) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      tmp[i][j] = arr[i][j] >= l;
      if (i > 0) {
        tmp[i][j] += tmp[i - 1][j];
      }
      if (j > 0) {
        tmp[i][j] += tmp[i][j - 1];
      }
      if (i > 0 && j > 0) {
        tmp[i][j] -= tmp[i - 1][j - 1];
      }
    }
  }

  for (int i = l - 1; i < n; i++) {
    for (int j = l - 1; j < m; j++) {
      int sum = tmp[i][j];
      if (i - l >= 0) {
        sum -= tmp[i - l][j];
      }
      if (j - l >= 0) {
        sum -= tmp[i][j - l];
      }
      if (i - l >= 0 && j - l >= 0) {
        sum += tmp[i - l][j - l];
      }
      if (sum >= l * l) {
        return true;
      }
    }
  }
  return false;
}

void solve() {
  cin >> n >> m;
  arr.clear();
  arr.resize(n, vector<int>(m));
  tmp.clear();
  tmp.resize(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> arr[i][j];
    }
  }
  int low = 1, high = 1000, best = 1;
  while (low <= high) {
    int mid = (low + high) >> 1;
    if (check(mid)) {
      best = mid;
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  cout << best << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int T;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
