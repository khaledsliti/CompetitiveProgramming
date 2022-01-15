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
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n; cin >> n;
  int q; cin >> q;
  map<int, vector<int>> pos;
  for(int i = 0; i < n; i++) {
    int a; cin >> a;
    pos[a].push_back(i);
  }
  for(int i = 0; i < q; i++) {
    int x; cin >> x;
    int k; cin >> k;
    if(pos.count(x) == 0 || sz(pos[x]) < k) cout << -1 << endl;
    else cout << pos[x][k - 1] + 1 << endl;
  }
  
  

  return 0;
}
