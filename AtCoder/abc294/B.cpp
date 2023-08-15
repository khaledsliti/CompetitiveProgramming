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

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, m;
  cin >> n >> m;
  vector<vector<int>> s(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      cin >> s[i][j];
      if (s[i][j] == 0) {
        s[i][j] = 150;
      } else {
        s[i][j] = char('A' + s[i][j] - 1);
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      cout << (s[i][j] == 150 ? '.' : char(s[i][j]));
    }
    cout << endl;
  }
  cout << endl;
  return 0;
}
