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

int n;

int main()
{
  cin >> n;
    vector<int> v;
  for(int i = 0; i < n * n; i++) {
    v.push_back(i + 1);
  }
  do {
    vector<vector<int>> g(n, vector<int>(n));
    int cur = 0;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        g[i][j] = v[cur++];
      }
    }
    bool ok = true;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        bool cur = false;
        for(int k = 0; k < n; k++) {
          if(g[i][j] > g[i][k] || g[i][j] < g[k][j]) {
            cur = true;
            break;
          }
        }
        if(!cur) {
          ok = false;
          break;
        }
      }
    }
    if(ok) {
      for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
          cout << g[i][j] << " ";
        }
        cout << endl;
      }
      cout << endl;
    }
  } while(next_permutation(all(v)));

  return 0;
}
