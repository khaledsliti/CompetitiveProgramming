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

const int N = 51;

int n, m;
int a[N][N];
int r[N], c[N];
int sr[N], sc[N];
int col[N][N];
int tmp[N][N];

int main()
{
  freopen("bwsquare.in", "r", stdin);
  freopen("bwsquare.out", "w", stdout);
  cin >> n >> m;
  int tot = 0;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      cin >> a[i][j];
      if(a[i][j]) {
        r[i]++;
        c[j]++;
        tot++;
      } else {
        sr[i] = 1;
        sc[j] = 1;
      }
    }
  }
  if(tot == n * m) {
    if(n <= m) {
      cout << n << endl;
      for(int i = 1; i <= n; i++)
        cout << -i << " ";
      cout << endl;
    } else {
      cout << m << endl;
      for(int i = 1; i <= m; i++) {
        cout << i << " ";
      }
      cout << endl;
    }
    return 0;
  }
  vector<int> sol;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(a[i][j] == 1) {
        if(sr[i] && sc[j]) {
          cout << -1 << endl;
          return 0;
        }
        if(tmp[i][j] == 1) {
          continue;
        }
        if(sr[i]) {
          sol.push_back(j + 1);
          for(int i = 0; i < n; i++) {
            tmp[i][j] = 1;
          }
        } else {
          sol.push_back(-(i + 1));
          for(int j = 0; j < m; j++) {
            tmp[i][j] = 1;
          }
        }
      } else if(!a[i][j] && tmp[i][j]) {
        cout << -1 << endl;
        return 0;
      }
    }
  }
  cout << sz(sol) << endl;
  for(int i = 0; i < sz(sol); i++) {
    cout << sol[i] << " ";
  }
  cout << endl;
  return 0;
}
