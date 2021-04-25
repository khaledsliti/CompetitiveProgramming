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

const int N = 11;

int n, m;
string s[N];
vector<int> row[N], col[N];

int main()
{
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    cin >> s[i];
  }
  for(int i = 0; i < n - 1; i++) {
    for(int j = 0; j < m; j++) {
      if(s[i][j] != s[i + 1][j]) {
        row[i].push_back(j);
      }
    }
  }
  for(int j = 0; j < m - 1; j++) {
    for(int i = 0; i < n; i++) {
      if(s[i][j] != s[i][j + 1]) {
        col[j].push_back(i);
      }
    }
  }
  int ans = 0;
  for(int i = 0; i < n; i++) {
    if(!sz(row[i])) continue;
    sort(all(row[i]));
    for(int j = 0; j < sz(row[i]); j++) {
      if(j == 0 || row[i][j - 1] + 1 != row[i][j]) {
        ans++;
      }
    }
  }
  for(int j = 0; j < m; j++) {
    if(!sz(col[j])) continue;
    sort(all(col[j]));
    for(int i = 0; i < sz(col[j]); i++) {
      if(i == 0 || col[j][i - 1] + 1 != col[j][i]) {
        ans++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
