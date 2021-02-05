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

const int N = 1005;

int n, m;
string s[N];

void solve() {
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    cin >> s[i];
  }
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(i != j && s[i][j] == s[j][i]) {
        cout << "YES" << endl;
        for(int k = 0; k <= m; k++) {
          if(k & 1) cout << i + 1 << " ";
          else cout << j + 1 << " ";
        }
        cout << endl;
        return;
      }
    }
  }
  if(m & 1) {
    cout << "YES" << endl;
    for(int i = 0; i <= m; i++) {
      if(i & 1) cout << "1 ";
      else cout << "2 ";
    }
    cout << endl;
    return;
  }
  if(n <= 2) {
    cout << "NO" << endl;
    return;
  }
  int l = m / 2;
  vector<int> nodes = {0, 1, 2};
  int a = -1, b, c;
  do {
    if(s[nodes[0]][nodes[1]] != s[nodes[0]][nodes[2]]) {
      a = nodes[0], b = nodes[1], c = nodes[2];
      break;
    }
  } while(next_permutation(all(nodes)));
  assert(a != -1);
  cout << "YES" << endl;
  if(l & 1) {
    for(int i = 0; i <= l; i++) {
      if(i & 1) cout << a + 1 << " ";
      else cout << b + 1 << " ";
    }
    for(int i = 0; i < l; i++) {
      if(i & 1) cout << a + 1 << " ";
      else cout << c + 1 << " ";
    }
    cout << endl;
  } else {
    for(int i = 0; i <= l; i++) {
      if(i & 1) cout << b + 1 << " ";
      else cout << a + 1 << " ";
    }
    for(int i = 0; i < l; i++) {
      if(i & 1) cout << a + 1 << " ";
      else cout << c + 1 << " ";
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
