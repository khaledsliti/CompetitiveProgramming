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



void solve() {
  int n;
  cin >> n;
  vector<vector<pair<int, int>>> diff(n * n);
  for (int i = 1; i <= n * n; i++) {
    for (int j = i + 1; j <= n * n; j++) {
      diff[j - i].push_back({i, j});
    }
  }

  vector<vector<int>> ans(n, vector<int>(n, 0));
  vector<pair<int, int>> at(n * n + 1, {-1, -1});
  ans[0][0] = 1;
  at[1] = {0, 0};
  for (int i = n * n - 1; i >= 1; i--) {
    
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
