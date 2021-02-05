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

int n;
vector<pair<int, int>> sol;

void solve(int st, int en) {
  if(st >= en) return;
  int mid = st + en >> 1;
  solve(st, mid);
  solve(mid + 1, en);
  for(int i = st, j = mid + 1; i <= mid; i++, j++) {
    sol.push_back({i, j});
  }
}

int main()
{
  cin >> n;
  int len = 1;
  while(len * 2 <= n) {
    len <<= 1;
  }
  solve(1, len);
  solve(n - len + 1, n);
  printf("%d\n", sz(sol));
  for(int i = 0; i < sz(sol); i++) {
    printf("%d %d\n", sol[i].first, sol[i].second);
  }
  return 0;
}
