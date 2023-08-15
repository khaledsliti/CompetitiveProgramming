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
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, q;
  cin >> n >> q;
  set<int> s;
  for (int i = 1; i <= n; i++) {
    s.insert(i);
  }

  while(q--) {
    int t;
    cin >> t;
    if (t == 1) {
      continue;
    }
    if (t == 2) {
      int x; cin >> x;
      s.erase(x);
      continue;
    }
    cout << *s.begin() << endl;
  }
  return 0;
}
