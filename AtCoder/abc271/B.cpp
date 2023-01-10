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

int n, q;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> q;
  vector<vector<int>> a(n);
  for(int i = 0; i < n; i++) {
    int l; cin >> l;
    a[i].resize(l);
    for(int j = 0; j < l; j++) {
      cin >> a[i][j];
    }
  }
  while(q--) {
    int s, t;
    cin >> s >> t;
    cout << a[--s][--t] << endl;
  }
  return 0;
}
