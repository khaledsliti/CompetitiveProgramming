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



int main()
{
  int n, k;
  cin >> n >> k;
  vector<int> v(n);
  for(int i = 0; i < n; i++) {
    cin >> v[i];
  }
  while(k--) {
    int a; cin >> a;
    int idx = lower_bound(all(v), a) - begin(v);
    if(idx < n && v[idx] == a) cout << "YES\n";
    else cout << "NO\n";
  }
  return 0;
}
