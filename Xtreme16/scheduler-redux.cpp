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

const int Mod = 1e9 + 7;
const int N = 100003;

int n, m;
int freq[N];
int pow2[N];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  pow2[0] = 1;
  for(int i = 1; i < N; i++) {
    pow2[i] = 2LL * pow2[i - 1] % Mod;
  }

  cin >> n >> m;
  int mx = 0;
  for(int i = 0; i < n ; i++) {
    int a; cin >> a;
    freq[a]++;
    mx = max(mx, a);
  }
  int ans = 0, x = -1;
  for(int i = mx; i >= 0; i--) {
    int q = freq[i] / m;
    ans = (ans + 1LL * q * pow2[i] % Mod) % Mod;
    if (freq[i] % m != 0 && x == -1) {
      x = i;
    }
  }
  ans = (ans + pow2[x]) % Mod;
  cout << ans << endl;
  return 0;
}
