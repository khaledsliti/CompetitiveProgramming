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

const int N = 10;

int n, m, k;
string g[N];

int main()
{
  cin >> n >> m >> k;
  for(int i = 0; i < n; i++) {
    cin >> g[i];
  }
  int ans = 0;
  for(int mr = 0; mr < (1 << n); mr++) {
    for(int mc = 0; mc < (1 << m); mc++) {
      int cnt = 0;
      for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
          if(g[i][j] == '#' && (mr & (1 << i)) && (mc & (1 << j))) {
            cnt++;
          }
        }
      }
      if(cnt == k) ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
