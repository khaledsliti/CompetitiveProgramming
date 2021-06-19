// Guess Who's Back
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;

bool fun(int n) {
  for(int i = 2; i < n; i++) {
    if(n % i == 0 && !fun(n - i)) {
      return true;
    }
  }
  return false;
}

int get(int n) {
  if(n <= 2) return 0;
  int x = n;
  int cnt = 0;
  int it = 0;
  while(n > 0) {
    cnt += n & 1;
    it += 1;
    n >>= 1;
  }
  if(cnt == 1) {
    if(it & 1) return 1;
    return 0;
  } else if(x % 2 == 0) {
    return 1;
  } else {
    return 0;
  }
}

void solve() {
  int n; cin >> n;
  cout << (get(n) ? "Alice" : "Bob") << endl;
}

int main()
{
  // for(int i = 1; i <= 20; i++)
  //   cout << i << " " << fun(i) << " " << get(i) << endl;
  // return 0;


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
