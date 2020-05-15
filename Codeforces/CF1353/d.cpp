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

const int N = 2e5 + 5;

int n;
int ans[N];

void solve() {
  cin >> n;
  set<pair<int, pair<int, int>>> seg;
  seg.insert({-n, {0, n - 1}});
  for(int it = 1; it <= n; it++) {
    auto s = *seg.begin();
    seg.erase(seg.begin());
    int l = s.second.first;
    int r = s.second.second;
    int mid = (l + r) / 2;
    ans[mid] = it;
    if(mid > l) seg.insert({-(mid - l), {l, mid - 1}});
    if(mid < r) seg.insert({-(r - mid), {mid + 1, r}});
  }
  for(int i = 0; i < n; i++)
    cout << ans[i] << " ";
  cout << endl;
}

int main()
{
  int T;
  cin >> T;
  while(T--) {
    solve();
  }
  return 0;
}
