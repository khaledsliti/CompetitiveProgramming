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



int main()
{
  int n, k, q;
  cin >> n >> k >> q;
  vector<int> ok(n, 0);
  vector<int> pos(k);
  for(int i = 0; i < k; i++) {
    cin >> pos[i];
    pos[i]--;
    ok[pos[i]] = 1;
  }
  while(q--) {
    int x;
    cin >> x;
    x--;
    if(pos[x] + 1 < n && !ok[pos[x] + 1]) {
      ok[pos[x]] = 0;
      pos[x]++;
      ok[pos[x]] = 1;
    }
  }
  for(int x: pos) cout << x + 1 << " "; cout << endl;
  return 0;
}
