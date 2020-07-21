// We only fail when we stop trying
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

const int N = 1e6 + 1;
const int K = 101;

int n, k;
int p[K];
int dp[N];

int main()
{
  cin >> n >> k;
  for(int i = 0; i < k; i++)
    cin >> p[i];
  dp[0] = 0;
  for(int i = 1; i <= n; i++) {
    dp[i] = 0;
    for(int j = 0; j < k; j++) {
      if(i - p[j] >= 0 && !dp[i - p[j]])
        dp[i] = 1;
    }
  }
  for(int i = 1; i <= n; i++)
    if(dp[i]) cout << 'W';
    else cout << 'L';
  cout << endl;
  return 0;
}
