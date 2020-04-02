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
  int n, k;
  cin >> n >> k;
  vector<int> v;
  for(int i = 2 ; i <= n ; i++) {
    while(n % i == 0) {
      n /= i;
      v.push_back(i);
    }
  }
  while(sz(v) > k)
    v[sz(v) - 2] *= v.back(), v.pop_back();
  if(sz(v) < k) cout << -1 << endl;
  else {
    for(int i : v)
      cout << i << " ";
    cout << endl;
  }
  return 0;
}
