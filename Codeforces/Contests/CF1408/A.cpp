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

const int N = 101;

int n;
int a[N][3];

void solve() {
  cin >> n;
  for(int j = 0; j < 3; j++)
    for(int i = 0; i < n; i++) {
      cin >> a[i][j];
    }
  vector<int> ans;
  ans.push_back(a[0][0]);
  for(int i = 1; i < n - 1; i++) {
    for(int j = 0; j < 3; j++) {
      if(a[i][j] != ans.back()) {
        ans.push_back(a[i][j]);
        break;
      }
    }
  }
  for(int i = 0; i < 3; i++) {
    if(a[n - 1][i] != ans.back() && a[n - 1][i] != ans.front()) {
      ans.push_back(a[n - 1][i]);
      break;
    }
  }

  for(int i = 0; i < n; i++) {
    cout << ans[i] << " ";
  }
  cout << endl;
}

int main()
{
  int T;
  cin >> T;
  while(T--) {
    solve();
  }
  return 0;
}
