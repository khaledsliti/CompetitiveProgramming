// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
typedef long long ll;

const int N = 1000005, V = 105;
const int Mod = 1e9 + 7;

int n, x;
int c[N];
int dp[N];

int main()
{
  cin >> n >> x;
  for(int i = 0; i < n; i++)
    cin >> c[i];
  dp[0] = 1;
  for(int i = 0; i < n; i++) {
    for(int j = c[i]; j <= x; j++)
      dp[j] = (dp[j] + dp[j - c[i]]) % Mod;
  }
  cout << dp[x] << endl;
  return 0;
}
