// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 1e5 + 5;
const int V = 1e6 + 1;
const int Mod = 1e9 + 7;

int n;
int arr[N], dp[N];
vector<int> d[V];

int main()
{
  for(int i = 1 ; i < V ; i++)
    for(int j = i ; j < V ; j += i)
      d[j].pb(i);
  scanf("%d", &n);
  for(int i = 0 ; i < n ; i++)
    scanf("%d", arr + i);
  for(int i = n - 1 ; i >= 0 ; i--) {
    for(int x : d[arr[i]])
      if(x <= n)
        dp[x] = (dp[x] + 1 + dp[x + 1]) % Mod;
  }
  cout << dp[1] << endl;
  return 0;
}
