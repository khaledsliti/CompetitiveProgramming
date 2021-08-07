// Guess Who's Back
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

const int N = 2e5 + 5;

int n;
string a, b;
int taken[N];

void solve() {
  cin >> n;
  cin >> a >> b;
  memset(taken, 0, n * sizeof(taken[0]));
  for(int i = 0; i < n; i++) {
    if(b[i] == '1') {
      if(i - 1 >= 0 && a[i - 1] == '1' && !taken[i - 1]) {
        taken[i - 1] = 1;
      } else if(a[i] == '0' && !taken[i]) {
        taken[i] = 1;
      } else if(i + 1 < n && a[i + 1] == '1' && !taken[i + 1]) {
        taken[i + 1] = 1;
      }
    }
    // for(int i = 0; i < n; i++) {
    //   cout << taken[i] << " ";
    // }
    // cout << endl;
  }
  int ans = 0;
  for(int i = 0; i < n; i++) {
    ans += taken[i];
  }
  cout << ans << endl;
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
