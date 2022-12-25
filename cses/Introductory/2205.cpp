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

int n;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  set<int> seen;
  int cur = 0;
  for(int i = 0; i < (1 << n); i++) {
    for(int j = n - 1; j >= 0; j--) {
      cout << ((cur >> j) & 1);
    }
    cout << endl;
    seen.insert(cur);
    for(int j = 0; j < n; j++) {
      int nxt = cur ^ (1 << j);
      if(seen.find(nxt) != seen.end()) {
        continue;
      }
      cur = nxt;
      break;
    }
  }

  return 0;
}


/*

000
001


010

011
111

110
100
101


*/
