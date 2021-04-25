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

const int N = 2e5 + 5;

int n, m;
string s, p;
int mn[N], mx[N];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  
  cin >> n >> m;
  cin >> s >> p;
  for(int i = 0, j = 0; i < m; i++) {
    while(j < n && p[i] != s[j]) j++;
    mn[i] = j++;
  }

  for(int i = m - 1, j = n - 1; i >= 0; i--) {
    while(j >= 0 && p[i] != s[j]) j--;
    mx[i] = j--;
  }

  int ans = 0;
  for(int i = 0; i < m - 1; i++) {
    ans = max(ans, mx[i + 1] - mn[i]);
  }

  cout << ans << endl;

  return 0;
}
