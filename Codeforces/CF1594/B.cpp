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

/*
1 3 9 27
1
  1
1 1
    1
1   1

*/

const int Mod = 1e9 + 7;
const int L = 30;

void solve() {
  long long n, k;
  cin >> n >> k;
  vector<long long> power(L);
  power[0] = 1;
  for(int i = 1; i < L; i++) {
    power[i] = n * power[i - 1] % Mod;
  }
  long long ans = 0;
  int i = 0;
  while(k > 0) {
    int cur = k & 1;
    if(cur) {
      ans = (ans + power[i]) % Mod;
    }
    k >>= 1;
    i++;
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
