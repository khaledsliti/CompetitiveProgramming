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

const int N = 5001;

int n;
int x[N];
ll cost[N][N];

int main()
{
  cin >> n;
  for(int i = 0; i < n; i++)
    cin >> x[i];
  for(int i = 0; i < n; i++)
    cost[i][i] = x[i];
  for(int len = 2; len <= n; len++) {
    for(int i = 0; i + len <= n; i++) {
      int j = i + len - 1;
      if(i == j) {
        cost[i][j] = x[i];
      } else {
        cost[i][j] = max(x[i] - cost[i + 1][j], x[j] - cost[i][j - 1]);
      }
    }
  }
  ll sum = 0;
  int i = 0, j = n - 1, it = 1;
  while(i <= j) {
    if(cost[i][j] == x[i] - cost[i + 1][j]) {
      if(it) sum += x[i];
      i++;
    } else {
      if(it) sum += x[j];
      j--;
    }
    it ^= 1;
  }
  cout << sum << endl;
  return 0;
}
