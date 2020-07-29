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

int n, m;
int par[N];

int fs(int x) { return x == par[x] ? x : par[x] = fs(par[x]); }

int main()
{
  ios::sync_with_stdio(false);
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    par[i] = i;
  }
  int ans = 0;  
  for(int i = 0; i < m ;i++) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    a = fs(a);
    b = fs(b);
    if(a == b) {
      ans++;
    } else {
      par[a] = b;
    }
  }

  cout << ans << endl;
  return 0;
}
