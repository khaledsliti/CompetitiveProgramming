// We only fail when we stop trying
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
vector<string> s;
vector<vector<int>> a, b;
vector<int> diag;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> m;
  s.resize(n);
  for(int i = 0; i < n; i++) {
    cin >> s[i];
  }
  a.resize(n, vector<int>(m, 0));
  b.resize(n, vector<int>(m, 0));
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(i == 0 && j == 0) a[i][j] = 1;
      else if(s[i][j] == '#') continue;
      else if(i > 0 && a[i - 1][j]) a[i][j] = 1;
      else if(j > 0 && a[i][j - 1]) a[i][j] = 1;
    }
  }
  for(int i = n - 1; i >= 0; i--) {
    for(int j = m - 1; j >= 0; j--) {
      if(i == n - 1 && j == m - 1) b[i][j] = 1;
      else if(s[i][j] == '#') continue;
      else if(i + 1 < n && b[i + 1][j]) b[i][j] = 1;
      else if(j + 1 < m && b[i][j + 1]) b[i][j] = 1;
    }
  }
  if(!a[n - 1][m - 1]) {
    cout << 0 << endl;
    return 0;
  }
  if(n == 1) {
    cout << 1 << endl;
    return 0;
  }
  diag.resize(n + m - 1, 0);
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(a[i][j] && b[i][j])
        diag[i + j]++;
    }
  }
  for(int i = 1; i < n + m - 2; i++)
    if(diag[i] == 1) {
      cout << 1 << endl;
      return 0;
    }
  

  cout << 2 << endl;
  return 0;
}
