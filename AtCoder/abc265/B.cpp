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

const int N = 1e5 + 5;

ll n, m, t;
ll a[N];
ll y[N];


int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m >> t;
  for(int i = 0; i < n - 1; i++) {
    cin >> a[i];
  }
  for(int i = 0; i < m; i++) {
    int x, yy;
    cin >> x >> yy;
    y[--x] = yy;
  }
  for(int i = 0; i < n - 1; i++) {
    t += y[i];
    if(t <= a[i]) {
      cout << "No" << endl;
      return 0;
    }
    t -= a[i];
  }
  cout << "Yes" << endl;
  return 0;
}
