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

const int N = 1e6 + 5;

int n, q;
int nxt[N];

int find(int x) {
  return nxt[x] == x ? x : nxt[x] = find(nxt[x]);
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> q;
  for(int i = 0; i <= n; i++) {
    nxt[i] = i;
  }
  
  while(q--) {
    char t;
    int x;
    cin >> t >> x;
    --x;
    if(t == '-') {
      nxt[x] = find(x + 1);
    } else {
      x = find(x);
      if(x == n) cout << -1 << endl;
      else cout << x + 1 << endl;
    }
  }

  return 0;
}
