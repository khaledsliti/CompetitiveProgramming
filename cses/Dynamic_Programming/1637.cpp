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

const int N = 1000003;

int n;
int dp[N];

int main()
{
  dp[0] = 0;
  cin >> n;
  for(int i = 1; i <= n; i++) {
    vector<int> dig;
    dp[i] = 1e9;
    for(int a = i; a > 0; a /= 10)
      dig.push_back(a % 10);
    sort(all(dig));
    dig.resize(unique(all(dig)) - begin(dig));
    for(int d : dig) {
      dp[i] = min(dp[i], 1 + dp[i - d]);
    }
  }
  cout << dp[n] << endl;
  return 0;
}
