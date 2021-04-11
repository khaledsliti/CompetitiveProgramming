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

int calc(vector<int>& a) {
  if(sz(a) & 1) return 1;
  return a[sz(a) / 2] - a[sz(a) / 2 - 1] + 1;
}

void solve() {
  int n;
  cin >> n;
  vector<int> x(n), y(n);
  for(int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
  }
  sort(all(x));
  sort(all(y));
  cout << 1LL * calc(x) * calc(y) << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  
  int T;
  cin >> T;
  while(T--) {
    solve();
  }
  return 0;
}
