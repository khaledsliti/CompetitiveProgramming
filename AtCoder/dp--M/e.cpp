// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 101, V = 1e5 + 1;

int n, w;
int vi[N], wi[N];
long long dp[V];

int main()
{
  cin >> n >> w;
  for(int i = 0 ; i < n ; i++)
    cin >> wi[i] >> vi[i];
  for(int i = 1 ; i < V ; i++)
    dp[i] = 1e18;
  for(int i = 1 ; i <= n ; i++) {
    for(int j = V - 1; j >= 0 ; j--) {
      if(j - vi[i - 1] >= 0)
        dp[j] = min(dp[j], dp[j - vi[i - 1]] + wi[i - 1]);
    }
  }
  for(int i = V - 1; i >= 0 ; i--) {
    if(dp[i] <= w) {
      cout << i << endl;
      return 0;
    }
  }
  return 0;
}
