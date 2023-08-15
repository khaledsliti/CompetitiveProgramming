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

const int N = 1005;

int n, k;
int arr[N][N];

void Solve() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> arr[i][j];
    }
  }
  int cnt = 0;
  int add = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (n - i - 1 == i && n - j - 1 == j) {
        add = 1;
        continue;
      }
      cnt += arr[i][j] != arr[n - i - 1][n - j - 1];
    }
  }
  cnt /= 2;
  if (cnt > k) {
    cout << "NO" << endl;
    return;
  }
  if ((k - cnt) % 2 == 0) {
    cout << "YES" << endl;
    return;
  }
  if (add) {
    cout << "YES" << endl;
    return;
  }
  cout << "NO" << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int T;
  cin >> T;
  while (T--) {
    Solve();
  }
  return 0;
}
