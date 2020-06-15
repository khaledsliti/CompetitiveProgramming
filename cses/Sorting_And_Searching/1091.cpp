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

struct cmp {
  bool operator() (const int& a, const int& b) {
    return a > b;
  }
};

int main()
{
  int n, m;
  cin >> n >> m;
  multiset<int, greater<int>> s;
  for(int i = 0; i < n; i++) {
    int a; cin >> a;
    s.insert(a);
  }
  for(int i = 0; i < m; i++) {
    int a; cin >> a;
    auto it = s.lower_bound(a);
    if(it == s.end()) cout << -1 << endl;
    else {
      cout << *it << endl;
      s.erase(it);
    }
  }
  return 0;
}
