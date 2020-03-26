// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 1e5 + 5;

int n;
int A[N], B[N], X[N];

void solve() {
  cin >> n;
  string s; cin >> s;
  for(int i = 0 ; i < n ; i++)
    X[i] = s[i] - '0', A[i] = B[i] = 0;
  bool done = false;
  for(int i = 0 ; i < n ; i++) {
    if(done) {
      A[i] = 0;
      B[i] = X[i];
    } else {
      if(X[i] == 2) A[i] = B[i] = 1;
      else if(X[i] == 0) A[i] = B[i] = 0;
      else A[i] = 1, B[i] = 0, done = true;
    }
  }
  for(int i = 0 ; i < n ; i++)
    cout << A[i];
  cout << endl;
  for(int i = 0 ; i < n ; i++)
    cout << B[i];
  cout << endl;
}

int main()
{
  int t;
  cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}
