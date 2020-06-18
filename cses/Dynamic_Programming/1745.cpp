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

const int N = 101;
const int V = 100001;

int n;
int dp[V];

int main()
{
  cin >> n;
  dp[0] = 1;
  for(int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    for(int j = V - 1; j >= x; j--) {
      dp[j] |= dp[j - x];
    }
  }
  vector<int> sol;
  for(int i = 1; i < V; i++) {
    if(dp[i])
      sol.push_back(i);
  }
  cout << sz(sol) << endl;
  for(int x : sol)
    cout << x << " ";
  cout << endl;
  return 0;
}
