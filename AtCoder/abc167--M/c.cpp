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

const int N = 12;

int n, m, x;
int val[N][N];
int cost[N];
int acc[N];

int main()
{
  cin >> n >> m >> x;
  for(int i = 0 ; i < n ; i++) {
    cin >> cost[i];
    for(int j = 0 ; j < m ; j++)
      cin >> val[i][j];
  }
  int best = 1e9;
  for(int msk = 1; msk < (1 << n); msk++) {
    for(int i = 0 ; i < m ; i++)
      acc[i] = 0;
    int tot = 0;
    for(int i = 0 ; i < n ; i++)
      if(msk & (1 << i)) {
        tot += cost[i];
        for(int j = 0 ; j < m ; j++) {
          acc[j] += val[i][j];
        }
      }
    bool good = true;
    for(int i = 0 ; i < m ; i++)
      good &= acc[i] >= x;
    if(good)
      best = min(best, tot);
  }
  if(best >= 1e9) best = -1;
  cout << best << endl;
  return 0; 
}
