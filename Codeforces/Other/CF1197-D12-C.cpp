#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

int n, k;
vector<int> v;
vector<int> diff;

int main()
{
  scanf("%d%d", &n, &k);
  for(int i = 0 ; i < n ; i++){
    int a; scanf("%d", &a);
    if(i)
      diff.pb(a - v.back());
    v.pb(a);
  }
  int ans = v.back() - v.front();
  sort(diff.rbegin(), diff.rend());
  for(int i = 0 ; i < k - 1 ; i ++)
    ans -= diff[i];
  cout << ans << endl;
  return 0;
}
