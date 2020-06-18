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

const int N = 1001;
const int V = 100006;

int n, x;
int c[N], v[N];
int dp[V];

int main()
{
  cin >> n >> x;
  for(int i = 0; i < n; i++)
    cin >> c[i];
  for(int i = 0; i < n; i++)
    cin >> v[i];
  for(int i = 0; i < n; i++) {
    for(int j = x; j >= 0; j--) {
      if(j >= c[i])
        dp[j] = max(dp[j], v[i] + dp[j - c[i]]);
    }
  }
  cout << dp[x] << endl;
  return 0;
}
