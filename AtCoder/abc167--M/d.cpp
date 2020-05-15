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
long long k;
int a[N], vis[N];

int main()
{
  cin >> n >> k;
  for(int i = 0 ; i < n ; i++)
    cin >> a[i], a[i]--;
  int cur = 0, root;
  vis[0] = 1;
  while(true) {
    cur = a[cur];
    if(!--k) {
      cout << cur + 1 << endl;
      return 0;
    }
    if(vis[cur]) {
      root = cur;
      break;
    }
    vis[cur] = 1;
  }
  vector<int> v {root};
  cur = a[root];
  while(cur != root) {
    v.push_back(cur);
    cur = a[cur];
  }
  k %= sz(v);
  cout << v[k] + 1 << endl;
  return 0;
}
