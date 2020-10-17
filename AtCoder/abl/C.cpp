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

int n;
int par[N];

int fs(int x) {
  return x == par[x] ? x : par[x] = fs(par[x]);
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int m;
  cin >> n >> m;
  iota(par, par + n, 0);
  int ans = n - 1;
  while(m--) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    a = fs(a), b = fs(b);
    if(a != b) {
      ans--;
      par[a] = b;
    }
  }
  cout << ans << endl;
  return 0;
}
