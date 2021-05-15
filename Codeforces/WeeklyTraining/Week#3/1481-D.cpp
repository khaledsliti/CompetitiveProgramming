// Guess Who's Back
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

const int N = 1001;

int n, m;
string s[N];

void solve() {
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    cin >> s[i];
  }

  for(int i = 0; i < n; i++) {
    for(int j = i + 1; j < n; j++) {
      int same = s[i][j] == s[j][i];
      if(same) {
        cout << "YES" << endl;
        for(int k = 0; k < m + 1; k++) {
          if(k & 1) cout << j + 1 << " ";
          else cout << i + 1 << " ";
        }
        cout << endl;
        return;
      }
    }
  }

  if(m & 1) {
    cout << "YES" << endl;
    for(int i = 0; i < m + 1; i++) {
      cout << 1 + (i & 1) << " ";
    }
    cout << endl;
    return;
  }

  if(n == 2) {
    cout << "NO" << endl;
    return;
  }

  vector<int> nodes {0, 1, 2};
  do {
    int a = nodes[0], b = nodes[1], c = nodes[2];
    if(max(a, max(b, c)) > n) continue;
    bool can = s[a][b] == s[b][c];
    if(can) {
      cout << "YES" << endl;
      int half = m / 2;
      vector<int> order;
      if(half & 1) {
        order = {a, b, c, b};
      } else {
        order = {b, c, b, a};
      }
      for(int i = 0; i < m + 1; i++)
        cout << order[i % 4] + 1 << " ";
      cout << endl;
      return;
    }
  } while(next_permutation(all(nodes)));

  cout << "NO" << endl;
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
