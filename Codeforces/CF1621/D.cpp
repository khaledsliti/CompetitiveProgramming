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

const int N = 507;

int n;
int arr[N][N];

void solve() {
  cin >> n;
  for(int i = 0; i < 2 * n; i++) {
    for(int j = 0; j < 2 * n; j++) {
      cin >> arr[i][j];
    }
  }
  long long ans = 0;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      ans += arr[i + n][j + n];
    }
  }
  int plus = min({arr[0][n], arr[0][2 * n - 1], arr[n - 1][n], arr[n - 1][2 * n - 1]});
  plus = min({plus, arr[n][0], arr[n][n - 1], arr[2 * n - 1][0], arr[2 * n - 1][n - 1]});
  ans += plus;
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
