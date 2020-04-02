// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

int ans[3];

int main()
{
  int n, m;
  cin >> n >> m;
  for(int i = 0 ; i < n ;i++)
    ans[i] = -1;
  while(m--) {
    int idx, c;
    cin >> idx >> c;
    --idx;
    if(~ans[idx] && ans[idx] != c) {
      cout << -1 << endl;
      return 0;
    }
    ans[idx] = c;
  }
  if(n > 1 && ans[0] == 0)
    return cout << -1 << endl, 0;
  if(ans[0] == -1) ans[0] = n == 1 ? 0 : 1;
  for(int i = 0 ; i < n ; i++) {
    if(ans[i] == -1) 
      ans[i] = 0;
    cout << ans[i];
  }
  return 0;
}
