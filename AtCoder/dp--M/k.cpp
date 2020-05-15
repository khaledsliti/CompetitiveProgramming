// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 101;
const int V = 100010;

int n, k;
int a[N];
int dp[V];

int main()
{
  cin >> n >> k;
  for(int i = 0 ; i < n ; i++)
    cin >> a[i];
  dp[0] = 0;
  for(int i = 1 ; i <= k ; i++) {
    dp[i] = 0;
    for(int j = 0 ; j < n ; j++) {
      if(i - a[j] >= 0 && !dp[i - a[j]]) {
        dp[i] = 1;
        break;
      }
    }
  }
  cout << (dp[k] ? "First" : "Second") << endl;
  return 0;
}
