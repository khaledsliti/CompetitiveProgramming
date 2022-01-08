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

const int N = 1e4 + 5;

int n;
int ans[N];

int ask(int x) {
  cout << "? " << x << endl;
  cout.flush();
  int y; cin >> y;
  return y;
}

void solve() {
  cin >> n;
  set<int> rem;
  for(int i = 1; i <= n; i++) {
    rem.insert(i);
  }
  while(sz(rem)) {
    int head = *rem.begin();
    vector<int> cycle;
    while(true) {
      int cur = ask(head);
      if(rem.find(cur) == rem.end()) {
        break;
      }
      rem.erase(cur);
      cycle.push_back(cur);
    }
    // cout << "cycle = ";
    // for(int i = 0; i < sz(cycle); i++) {
    //   cout << cycle[i] << " ";
    // }
    // cout << endl;
    for(int i = 0; i < sz(cycle); i++) {
      int j = (i + 1) % sz(cycle);
      ans[cycle[i]] = cycle[j];
    }
  }
  cout << "! ";
  for(int i = 1; i <= n; i++) {
    cout << ans[i] << " ";
  }
  cout << endl;
  cout.flush();
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
