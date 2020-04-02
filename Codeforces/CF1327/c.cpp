// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 203;

int n, m, k;
array<int, 2> s[N], e[N];
string ans;

int main()
{
  cin >> n >> m >> k;
  for(int i = 0 ; i < k ; i++) {
    cin >> s[i][0] >> s[i][1];
  }
  for(int i = 0 ; i < k ; i++) {
    cin >> e[i][0] >> e[i][1];
  }
  for(int i = 1 ; i < n ; i++)
    ans += 'U';
  for(int i = 1 ; i < m ; i++)
    ans += 'L';
  int d = 0;
  for(int i = 0 ; i < n ; i++) {
    if(i > 0) ans += 'D';
    for(int j = 1 ; j < m ; j++)
      ans += (d == 0 ? 'R' : 'L');
    d = !d;
  }
  cout << sz(ans) << endl;
  cout << ans << endl;
  return 0;
}
