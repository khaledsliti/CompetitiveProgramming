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

const int INF = 1e9;

void solve() {
  int n;
  cin >> n;
  string s[n];  
  for(int i = 0; i < n; i++) {
    cin >> s[i];
  }
  vector<int> rowX(n, 0), rowO(n, 0);
  vector<int> colX(n, 0), colO(n, 0);
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(s[i][j] == 'X') rowX[i]++, colX[j]++;
      if(s[i][j] == 'O') rowO[i]++, colO[j]++;
    }
  }
  int best = INF;
  int ways = 0;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(s[i][j] == '.' && (rowX[i] == n - 1 || colX[j] == n - 1)) {
        ways++;
        best = 1;
      }
    }
  }
  if(best >= INF) {
    for(int i = 0; i < n; i++) {
      if(rowO[i] == 0) {
        int cur = n - rowX[i];
        if(cur == best) {
          ways++;
        } else if(cur < best) {
          best = cur;
          ways = 1;
        }
      }
    }
    for(int i = 0; i < n; i++) {
      if(colO[i] == 0) {
        int cur = n - colX[i];
        if(cur == best) {
          ways++;
        } else if(cur < best) {
          best = cur;
          ways = 1;
        }
      }
    }
  }

  if(best >= INF) {
    cout << "Impossible" << endl;
  } else {
    cout << best << " " << ways << endl;
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int T;
  cin >> T;
  for(int tc = 1; tc <= T; tc++) {
    cout << "Case #" << tc << ": ";
    solve();
  }
  return 0;
}
