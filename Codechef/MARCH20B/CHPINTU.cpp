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
  int T;
  cin >> T;
  while(T--) {
    int n, m;
    cin >> n >> m;
    vector<int> f(n);
    for(int i = 0 ; i < n ; i++)
      cin >> f[i];
    map<int, int> cnt;
    for(int i = 0 ; i < n ; i++) {
      int a;
      cin >> a;
      cnt[f[i]] += a;
    }
    int best = 1e9;
    for(auto x : cnt)
      best = min(best, x.second);
    cout << best << endl;
  }
  return 0;
}
