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

unordered_map<long long, int> cnt;

long long calc(long long a, long long b) {
  long long ans = 0;
  for(int len_a = 1; len_a <= a; len_a++) {
    for(int len_b = 1; len_b <= b; len_b++) {
      ans += 1LL * (a - len_a + 1) * (b - len_b + 1);
    }
  }
  return ans;
}

void solve() {

}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

#ifndef LOCAL
  freopen("bowling.in", "r", stdin);
#endif

  cout << calc(10000, 10000) << endl;

  int T;
  cin >> T;
  while(T--) {
    solve();
  }
  return 0;
}

/*

A * B -> [A (A - 1) / 2] * [B (B - 1) / 2]

*/