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

string s;

int main()
{
  cin >> s;
  if (s[0] == '1') {
    cout << "No" << endl;
    return 0;
  }
  vector<vector<int>> c {
    {7},
    {4},
    {2, 8},
    {1, 5},
    {3, 9},
    {6},
    {10}
  };

  auto down = [&](int j) -> bool {
    for(int x: c[j]) {
      if(s[x - 1] == '1') {
        return false;
      }
    }
    return true;
  };
  for(int i = 0; i < 7; i++) {
    if(down(i)) continue;
    for(int j = i + 2; j < 7; j++) {
      if(down(j)) continue;
      bool ex = false;
      for(int k = i + 1; k < j; k++) {
        if(down(k)) {
          ex = true;
          break;
        }
      }
      if(ex) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
  return 0;
}
