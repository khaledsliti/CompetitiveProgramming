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
  int n, k;
  cin >> n >> k;
  vector<vector<int>> t(n, vector<int>(n));
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      cin >> t[i][j];
    }
  }
  vector<int> nodes;
  for(int i = 1; i < n; i++) {
    nodes.pb(i);
  }
  int ans = 0;
  do {
    int cost = 0, last = 0;
    for(int i = 0; i < sz(nodes); i++) {
      cost += t[last][nodes[i]];
      last = nodes[i];
    }
    cost += t[last][0];
    if(cost == k) {
      ans++;
    }
  } while(next_permutation(all(nodes)));
  cout << ans << endl;
  return 0;
}
