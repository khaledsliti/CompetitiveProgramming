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

void solve() {
  int n;
  cin >> n;
  string s; cin >> s;
  vector<int> acc(n, 0);
  for(int i = 0; i < n; i++) {
    acc[i] = s[i] == '1';
    if(i > 0) acc[i] += acc[i - 1];
  }
  if(acc[n - 1] == n) {
    cout << 1 << " " << n - 1 << " " << 2 << " " << n << endl;
    return;
  }
  for(int i = n / 2; i < n; i++) {
    if(s[i] == '0') {
      cout << 1 << " " << i + 1 << " " << 1 << " " << i << endl;
      return;
    }
  }
  for(int i = 0; i < n / 2; i++) {
    if(s[i] == '0') {
      cout << i + 1 << " " << n << " " << i + 2 << " " << n << endl;
      return;
    }
  }
  assert(false);
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
