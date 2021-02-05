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
string s[100];

int main()
{
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    cin >> s[i];
  }
  int ans = 0;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(i + 1 < n && s[i][j] == '.' && s[i + 1][j] == '.') ans++;
      if(j + 1 < m && s[i][j] == '.' && s[i][j + 1] == '.') ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
