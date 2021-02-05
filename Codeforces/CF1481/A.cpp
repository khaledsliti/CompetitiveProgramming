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

int px, py;
string s;

void solve() {
  cin >> px >> py >> s;
  int max_x = 0, min_x = 0, max_y = 0, min_y = 0;
  for(char c: s) {
    if(c == 'U') max_y++;
    else if(c == 'D') min_y--;
    else if(c == 'R') max_x++;
    else min_x--;
  }
  if(px >= min_x && px <= max_x && py >= min_y && py <= max_y) cout << "YES" << endl;
  else cout << "NO" << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int T;
  cin >> T;
  while(T--) {
    solve();
  }
  return 0;
}
