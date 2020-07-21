// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;

const int N = 1e5 + 5;

int n, x;
int arr[N];

void solve() {
  scanf("%d%d", &n, &x);
  multiset<pair<int, int>> a;
  for(int i = 0; i < n; i++) {
    scanf("%d", arr + i);
    a.insert({arr[i], i});
  }
  int ans = 0;
  while(sz(a)) {
    ++ans;
    auto it = a.lower_bound({x, -1});
    if(it != a.end()) {
      int v = it->first;
      int idx = it->second;
      a.erase(it);
      if(v > x) {
        v = min(arr[idx], (v - x) * 2);
        a.insert({ min((v - x) * 2, arr[idx]), idx });
      }
      x <<= 1;
    } else {
      a.erase(a.begin());
    }
  }
  cout << ans << endl;
}

int main()
{
  int T;
  scanf("%d", &T);
  while(T--)
    solve();
  return 0;
}
