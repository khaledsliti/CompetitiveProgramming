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

const int N = 200;

int n, m;
string s[N];

int main()
{
  cin >> n >> m;
  vector<pair<int, int>>  pts;
  for(int i = 0; i < n; i++) {
    cin >> s[i];
    for(int j = 0; j < m; j++) {
      if(s[i][j] == 'o') {
        pts.push_back({i, j});
      }
    }
  }
  cout << abs(pts[0].first - pts[1].first) + abs(pts[0].second - pts[1].second) << endl;
  return 0;
}
