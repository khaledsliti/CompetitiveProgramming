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

const int N = 2e5 + 4;

int n;
ll a[N], b[N];

void Solve() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
  }

  int ans = 0;
  for (int i = 0; i < n; i++) {
    int last_g = a[i];
    int j = i + 1;
    while (j < n) {
      ll g = __gcd(a[i] * b[i], a[j] * b[j]);
      ll q1 = a[i] * b[i] / g;
      ll q2 = a[j] * b[j] / g;
      if (last_g % q1 != 0 || a[j] % q2 != 0) {
        break;
      }
      a[i] /= q1;
      a[j] /= q2;
      last_g = __gcd(last_g / q1, a[j]);
      j++;
    }
    ans++;
    i = j - 1;
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
    Solve();
  }
  return 0;
}
