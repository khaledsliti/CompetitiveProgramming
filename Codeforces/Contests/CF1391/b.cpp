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

const int N = 105;

int n, m;
string s[N];

int main()
{
  int T;
  cin >> T;
  while(T--) {
    cin >> n >> m;
    for(int i = 0; i < n; i++)
      cin >> s[i];
    int ans = 0;
    for(int i = 0; i < n - 1; i++) {
      ans += s[i][m - 1] == 'R';
    }
    for(int j = 0; j < m - 1; j++) {
      ans += s[n - 1][j] == 'D';
    }
    cout << ans << endl;
  }
  return 0;
}
