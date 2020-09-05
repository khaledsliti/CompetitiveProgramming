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

const int N = 1e5 + 5;

int n;
int pre[N], ind[N];

void dfs(int l, int r, int& idx) {
  if(l > r) return;
  int cur = pre[idx++];
  int i = ind[cur];
  if(i > l) dfs(l, i - 1, idx);
  if(i < r) dfs(i + 1, r, idx);
  cout << cur << " ";
}

int main()
{
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> pre[i];
  }
  for(int i = 0; i < n; i++) {
    int a;
    cin >> a;
    ind[a] = i;
  }
  int cur = 0;
  dfs(0, n - 1, cur);
  return 0;
}
