#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

int main()
{
  int n;
  cin >> n;
  vector<int> v(n), sum(n);
  for(int i = 0 ; i < n ; i++){
    int a;
    cin >> a;
    v[i] = a;
    sum[i] = a;
    if(i) sum[i] += sum[i - 1];
  }
  int ans = 1e8;
  for(int i = 0 ; i < n ; i++){
    ans = min(ans, abs(sum[n - 1] - sum[i] * 2));
  }
  cout << ans << endl;
  return 0;
}
