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

const int Mod = 998244353;

ll sum(int n) {
  return 1LL * n * (n + 1) / 2 % Mod;
}

int main()
{
  int A, B, C;
  cin >> A >> B >> C;
  ll ans = sum(A) * sum(B) % Mod * sum(C) % Mod;
  cout << ans << endl;
  return 0;
}
