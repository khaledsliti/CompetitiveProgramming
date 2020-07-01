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
  ll a, b, c;
  cin >> a >> b >> c;
  if(a < c) {
    cout << 1 << " ";
  } else {
    cout << -1 << " ";
  }
  if(a * b > c) {
    cout << b << endl;
  } else {
    cout << -1 << endl;
  }
}

int main()
{
  int T;
  cin >> T;
  while(T--)
    solve();
  return 0;
}
