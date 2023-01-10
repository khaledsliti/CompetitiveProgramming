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

const int N = 2e5 + 4;

int n;
int a[N], b[N];

void solve() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for(int i = 0; i < n; i++) {
    cin >> b[i];
  }
  for(int i = 0; i < n; i++) {
    if(b[i] < a[i]) {
      cout << "NO" << endl;
      return;
    }
  }
  for(int it = 0; it < 3; it++) {
    int st = n - 1;
    for(int i = n - 2; i >= 0; i--) {
      if(a[st] < a[i]) {
        st = i;
      }
    }
    for(int it = 0; it < n; it++) {
      a[st] = max(a[st], min(a[(st + 1) % n] + 1, b[st]));
      if(--st < 0) {
        st = n - 1;
      }
    }
  }
  // for(int i = 0; i < n; i++) {
  //   cout << a[i] << " ";
  // }
  // cout << endl;
  bool same = true;
  for(int i = 0; i < n; i++) {
    same &= a[i] == b[i];
  }
  if(same) {
    cout << "YES" << endl;
    return;
  }
  cout << "NO" << endl;
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