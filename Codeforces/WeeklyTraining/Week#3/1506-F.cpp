// RedStone
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

const int N = 2e5 + 5;

int n;
pair<int, int> arr[N];

pair<int, int> go(pair<int, int> cur, pair<int, int> target, int& cost) {
  if(cur == target) return cur;
  int dr = target.first - cur.first;
  int dc = target.second - cur.second;
  int parity = (cur.first + cur.second) & 1;
  // should always move left
  if(dc == 0) {
    if(parity == 0) cost += dr / 2;
    else cost += (dr + 1) / 2;
    return target;
  }
  // should always move right
  if(dr == dc) {
    if(parity == 0) cost += dr;
    return target;
  }
  if(parity == 0) {
    return {cur.first + 1, cur.second};
  }
  return {cur.first + dc, cur.second + dc};
}

void solve() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> arr[i].first;
  }
  for(int i = 0; i < n; i++) {
    cin >> arr[i].second;
  }
  sort(arr, arr + n);
  pair<int, int> cur = {1, 1};
  int ans = 0;
  for(int i = 0; i < n; i++) {
    while(true) {
      cur = go(cur, arr[i], ans);
      if(cur == arr[i]) break;
    }
  }
  printf("%d\n", ans);
}

int main()
{
  int T;
  scanf("%d", &T);
  while(T--)
    solve();
  return 0;
}
