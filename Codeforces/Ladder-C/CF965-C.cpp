// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
 
int main()
{
  long long n, k, M;
  int D;
  cin >> n >> k >> M >> D;
  long long res = 0;
  for(int d = 1; d <= D; d++) {
    if(d > 1 && k > (n - 1) / (d - 1)) continue;
    long long x = n / (1 + k * (d - 1));
    if(x > M) x = M;
    res = max(res, x * d);
  }
  cout << res << endl;
  return 0;
}