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
  int n, m;
  cin >> n >> m;
  if(n > m)
    return cout << 0 << endl, 0;
  vector<int> v(n);
  int ans = 1;
  for(int i = 0 ; i < n ; i++) {
    cin >> v[i];
    for(int j = 0 ; j < i ; j++)
      ans = (ans * (abs(v[i] - v[j]) % m) % m) % m;
  }
  cout << ans << endl;
  return 0;
}
