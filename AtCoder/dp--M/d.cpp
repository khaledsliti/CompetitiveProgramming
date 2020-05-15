// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 101, W = 1e5 + 1;

int n, w;
int vi[N], wi[N];
long long dp[W];

int main()
{
  cin >> n >> w;
  for(int i = 0 ; i < n ; i++)
    cin >> wi[i] >> vi[i];
  for(int i = 1 ; i <= n ; i++) {
    for(int j = w ; j >=0 ; j--) {
      if(j - wi[i - 1] >= 0) {
        dp[j] = max(dp[j], vi[i - 1] + dp[j - wi[i - 1]]);
      }
    }
  }
  cout << dp[w] << endl;
  return 0;
}
