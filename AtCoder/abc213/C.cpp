// Guess Who's Back
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

int r, c, n;
int x[N], y[N];
map<int, int> xs, ys;

void pre(map<int, int>& a) {
  int cur = 0;
  for(auto& x: a) {
    x.second = cur++;
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> r >> c >> n;
  for(int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
    xs[x[i]];
    ys[y[i]];
  }
  pre(xs);
  pre(ys);
  for(int i = 0; i < n; i++) {
    cout << xs[x[i]] + 1 << " " << ys[y[i]] + 1 << endl;
  }
  return 0;
}
