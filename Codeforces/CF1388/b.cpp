// We only fail when we stop trying
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

const int N = 6e5 + 5;

int n;
int a[N];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int T;
  cin >> T;
  while(T--) {
    cin >> n;
    for(int i = 0; i < 4 * n; i++) {
      a[i] = (i % 4 == 0 || i % 4 == 3) ? 1 : 0;
    }
    for(int i = 0; i < n; i++) {
      a[4 * n - 1 - i] = 0;
    }
    for(int i = 0; i < n; i++) {
      int cur = 0;
      for(int j = 0; j < 4; j++) {
        if(a[4 * i + j])
          cur |= (1 << (3 - j));
      }
      if(cur == 9) cout << 9;
      else cout << 8;
    }
    cout << endl;
  }
  return 0;
}
