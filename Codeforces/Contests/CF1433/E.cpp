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

const int N = 22;

ll fact[N];
ll C[N][N];

ll ways(int n) {
  if(n <= 2) return 1;
  return fact[n - 1];
}

int main()
{
  fact[0] = 1;
  for(int i = 1; i < N; i++) {
    fact[i] = fact[i - 1] * i;
  }
  for(int i = 0; i < N; i++) {
    for(int j = 0; j <= i; j++) {
      if(j == 0 || j == i) C[i][j] = 1;
      else C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
    }
  }

  int n;
  while(cin >> n) {
    ll ans = C[n - 1][n / 2] * ways(n / 2) * ways(n / 2);
    cout << ans << endl;
  }
  return 0;
}
