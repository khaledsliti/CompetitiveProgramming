// We only fail when we stop trying
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

void solve() {
  int n;
  ll s = 1;
  cin >> n;
  for(int i = 2; i <= n; i++) {
    int a; cin >> a;
    s += i - a;
  }
  cout << s << endl;
}

int main()
{
  int T = 1;
  while(T--)
    solve();
  return 0;
}
