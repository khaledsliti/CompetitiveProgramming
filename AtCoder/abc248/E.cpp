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

const int N = 304;
#define X first
#define Y second

int n, k;
int x[N], y[N];

void red(int& a, int& b) {
  int g = __gcd(abs(a), abs(b));
  a /= g;
  b /= g;
  if(1LL * a * b >= 0) a = abs(a), b = abs(b);
  else a = -abs(a), b = abs(b);
}

int calc(pair<int, int> a, pair<int, int> b, int& f) {
  int ans = 0;
  for(int i = 0; i < n; i++) {
    pair<int, int> c = {x[i], y[i]};
    bool ok = 1LL * (b.Y - a.Y) * (c.X - a.X) == 1LL * (c.Y - a.Y) * (b.X - a.X);
    if(ok) {
      if(f == -1) {
        f = i;
      }
      ans++;
    }
  }
  return ans;
}

int main()
{
  cin >> n >> k;
  for(int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
  }
  if(n == 1 || k == 1) {
    cout << "Infinity" << endl;
    return 0;
  }
  set<vector<int>> slopes;
  for(int i = 0; i < n; i++) {
    for(int j = i + 1; j < n; j++) {
      int a = y[j] - y[i], b = x[j] - x[i];
      red(a, b);
      int f = -1;
      if(calc({x[i], y[i]}, {x[j], y[j]}, f) >= k) {
        slopes.insert({f, a, b});
      }
    }
  }
  cout << slopes.size() << endl;
  return 0;
}
