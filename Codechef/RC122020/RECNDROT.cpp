// We only fail when we stop trying
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace std;
using namespace __gnu_pbds;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 200011;

int n;
int arr[N];
vector<int> pos[N];

void solve() {
  scanf("%d", &n);
  map<int, int> id;
  for(int i = 0 ; i < n ; i++) {
    scanf("%d", &arr[i]);
    id[arr[i]];
  }
  int cur = 0;
  for(auto x : id)
    id[x.first] = cur++;
  for(int i = 0 ; i < n ; i++) {
    arr[i] = id[arr[i]];
    pos[arr[i]].clear();
  }
  for(int i = 0 ; i < n ; i++) {
    pos[arr[i]].push_back(i);
  }
  int idx = 0;
  int ans = 1;
  for(auto x : id) {
    int value = x.second;
    int nxt = lower_bound(pos[value].begin(), pos[value].end(), idx) - begin(pos[value]);
    if(nxt >= sz(pos[value])) {
      ++ans;
      nxt = 0;
    }
    idx = pos[value][nxt];
  }
  printf("%d\n", ans);
}

int main()
{
  int T;
  scanf("%d", &T);
  while(T--) {
    solve();
  }
  return 0;
}
