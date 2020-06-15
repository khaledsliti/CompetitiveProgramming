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
  map<int, int> old;
  int n, x;
  cin >> n >> x;
  for(int i = 0; i < n; i++) {
    int a; cin >> a;
    if(old.count(x - a)) {
      cout << old[x - a] << " " << i + 1 << endl;
      return 0;
    }
    old.insert({a, i + 1});
  }
  cout << "IMPOSSIBLE" << endl;
  return 0;
}
