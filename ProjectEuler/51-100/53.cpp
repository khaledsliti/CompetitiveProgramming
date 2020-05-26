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
const ll Inf = 2e18;

int n;
ll k;
ll C[N][N];

int main()
{
  cin >> n >> k;
  int tot = 0;
  for(int i = 0; i <= n; i++) {
    for(int j = 0; j <= i; j++) {
      if(j == 0 || j == i) C[i][j] = 1;
      else C[i][j] = min(Inf, C[i - 1][j] + C[i - 1][j - 1]);
      tot += C[i][j] > k;
    }
  }
  cout << tot << endl;
  return 0;
}
