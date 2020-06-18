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
  long long n;
  cin >> n;
  while(n > 1) {
    cout << n << " ";
    if(n & 1) n = n * 3 + 1;
    else n >>= 1;
  }
  cout << 1 << endl;
}

int main()
{
  int T = 1;
  while(T--)
    solve();
  return 0;
}
