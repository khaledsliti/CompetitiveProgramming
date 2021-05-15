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


void solve() {
  int n;
  vector<int> a(n);
  int target = 0;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    target += a[i];
  }
  if(target % n != 0) {
    cout << -1 << endl;
    return;
  }
  target /= n;
  
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
