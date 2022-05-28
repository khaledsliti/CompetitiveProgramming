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
  cin >> n;
  vector<int> a(n + 1);
  int one = -1;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    if(a[i] == 1) {
      one = i;
    }
  }
  if(one == -1) {
    cout << "No" << endl;
    return;
  }
  for(int i = 0; i < n; i++) {
    if(i != one && a[i] == 1) {
      cout << "No" << endl;
      return;
    }
  }
  a[n] = a[0];
  for(int i = 0; i < n; i++) {
    if(a[i + 1] >= a[i] + 2) {
      cout << "No" << endl;
      return;
    }
  }
  cout << "Yes" << endl;
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
