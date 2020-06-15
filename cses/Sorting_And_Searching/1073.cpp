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
  int n;
  cin >> n;
  multiset<int> t;
  for(int i = 0; i < n; i++) {
    int a; cin >> a;
    auto it = t.upper_bound(a);
    if(it != t.end()) t.erase(it);
    t.insert(a);
  }
  cout << sz(t) << endl;
  return 0;
}
