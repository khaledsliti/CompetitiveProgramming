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

int n;
string s;
int w[N];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> s;
  for(int i = 0; i < n; i++) {
    cin >> w[i];
  }
  vector<pair<int, int>> p;
  int z = 0;
  for(int i = 0; i < n; i++) {
    p.push_back({w[i], s[i] - '0'});
    z += p.back().second == 0;
  }
  sort(all(p));
  int ans = z;
  int o = 0;
  for(int i = n - 1; i >= 0; i--) {
    if(p[i].second) {
      o++;
    } else {
      z--;
    }
    if (i == 0 || p[i - 1].first < p[i].first) {
      ans = max(ans, z + o);
    }
  }
  cout << ans << endl;
  return 0;
}
