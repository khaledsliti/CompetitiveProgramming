// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()



void solve() {
  long long n, d;
  cin >> n >> d;
  vector<long long> a(n);
  for(int i = 0 ; i < n ; i++)
    cin >> a[i];
  for(int i = n - 1 ; i >= 0 ; i--) {
    d = d / a[i] * a[i];
  }
  cout << d << endl;
}

int main()
{
  int T, tc = 1;
  cin >> T;
  while(T--) {
    cout << "Case #" << tc++ << ": ";
    solve();
  }
  return 0;
}
