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

int n, m;
vector<string> a;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m;
  a.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if (a[i][j] != '#') {
        continue;
      }
      bool gone = false;
      for (int k = 0; k < n; k++) {
        for (int l = 0; l < m; l++) {
          if (a[k][l] < '0' || a[k][l] > '9') {
            continue;
          }
          int v = a[k][l] - '0';
          if (abs(i - k) + abs(j - l) <= v) {
            gone = true;
          }
        }
      }
      if (gone) {
        a[i][j] = '.';
      }
    }
  }

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(a[i][j] != '#') {
        a[i][j] = '.';
      }
    }
  }

  for (int i = 0; i < n; i++) {
    cout << a[i] << endl;
  }
  return 0;
}
