// RedStone
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;

const int N = 1e5 + 6;

int n;
int arr[2][N];

void Solve() {
  cin >> n;
  arr[0][0] = 2 * n;
  int c = 1;
  int cur = 1;
  for (int i = 0; i < n; i++) {
    arr[c][i] = cur++;
    c ^= 1;
  }

  c = 1;
  for (int i = 1; i < n; i++) {
    arr[c][i] = cur++;
    c ^= 1;
  }
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < n; j++) {
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }
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
