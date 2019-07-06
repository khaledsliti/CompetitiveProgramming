#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

int main()
{
  int n, k, p;
  cin >> n >> p >> k;
  unordered_map<int, int> occ;
  for(int i = 0 ; i < n ; i++) {
    int a;
    cin >> a;
    int cur = 1;
    for(int it = 0 ; it < 4 ; it++)
      cur = (1LL * cur * a) % p;
    cur = ((cur - 1LL * k * a) % p + p) % p;
    occ[cur]++;
  }
  long long ans = 0;
  for(auto x : occ){
    int cnt = x.second;
    ans += 1LL * cnt * (cnt - 1) / 2;
  }
  cout << ans << endl;
  return 0;
}
