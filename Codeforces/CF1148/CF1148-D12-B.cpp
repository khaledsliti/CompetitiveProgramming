#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
typedef long long ll;
const int mod = 1e9 + 7;

const int N = 2e5 + 5;

int n, m, ta, tb, k;
int a[N], b[N];

int main()
{
  scanf("%d%d%d%d%d", &n, &m, &ta, &tb, &k);
  for(int i = 0 ; i < n ; i++){
    scanf("%d", a + i);
    a[i] += ta;
  }
  for(int i = 0 ; i < m ; i++)
    scanf("%d", b + i);
  if(min(n, m) <= k){
    cout << -1 << endl;
    return 0;
  }
  sort(a, a + n);
  sort(b, b + m);
  // for(int i = 0 ; i < n ; i++)
  //   cout << a[i] << " ";
  // cout << endl;
  // for(int i = 0 ; i < m ; i++)
  //   cout << b[i] << " ";
  // cout << endl;
  long long ans = 0;
  for(int i = 0 ; i < min(n, k + 1) ; ++i){
    int idx = lower_bound(b, b + m, a[i]) - b;
    int rem = k - i;
    if(idx + rem >= m){
      cout << -1 << endl;
      return 0;
    }
    idx += rem;
    // cout << i << " " << idx << " " << b[idx] + tb << endl;
    ans = max(ans, 1LL * b[idx] + tb);
  }
  cout << ans << endl;
  return 0;
}