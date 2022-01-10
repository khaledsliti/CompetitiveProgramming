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
  int a[3];
  for(int i = 0; i < 3; i++) {
    cin >> a[i];
  }
  sort(a, a + 3);
  if(a[2] == a[1] + a[0]) {
    cout << "YES" << endl;
    return;
  }
  do {
    if(a[0] % 2 == 0 && a[1] == a[2]) {
      cout << "YES" << endl;
      return;
    }
  } while(next_permutation(a, a + 3));
  cout << "NO" << endl;
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
