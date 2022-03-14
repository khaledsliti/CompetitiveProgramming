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

const int N = 2e5 + 6;

void solve() {
  int n;
  cin >> n;
  int lg = 1;
  while((1 << lg) <= n - 1) lg++;
  lg--;
  set<int> seen;
  vector<int> sol;
  int cnt = 0;
  for(int i = n - 1; i >= 0; i--) {
    if(i & (1 << lg)) {
      cnt++;
    }
  }
  int t = (cnt & 1) == 0;
  for(int i = n - 1; i >= 0; i--) {
    if(i & (1 << lg)) {
      int a = i, b = i ^ (1 << lg);
      seen.insert(a), seen.insert(b);
      if(t) swap(a, b);
      // D(a); D(b);
      sol.push_back(a);
      sol.push_back(b);
      t ^= 1;
    }
  }
  for(int i = 0; i < n; i++) {
    if(seen.find(i) == seen.end()) {
      sol.push_back(i);
    }
  }
  int x = 0;
  for(int i = 0; i < n - 1; i++) {
    x = max(x, sol[i + 1] ^ sol[i]);
  }
  for(int x: sol) {
    cout << x << " ";
  }
  cout << endl;
  // cout << x << endl;
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
