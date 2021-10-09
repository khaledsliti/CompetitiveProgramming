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

const int N = 3e5 + 5;

int n;
char c;
string s;

void solve() {
  cin >> n >> c >> s;
  int all_c = 1;
  for(char x: s) {
    if(x != c) {
      all_c = false;
    }
  }
  if(all_c) {
    cout << 0 << endl;
    return;
  }
  for(int i = 1; i <= n; i++) {
    int cnt = 0;
    for(int j = i; j <= n; j += i) {
      cnt += s[j - 1] != c;
    }
    if(cnt == 0) {
      cout << 1 << endl;
      cout << i << endl;
      return;
    }
  }
  cout << 2 << endl;
  cout << n - 1 << " " << n << endl;
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
