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

const int N = 1e3 + 5;

int n;
int a[N], ans[N];

void solve() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  reverse(a, a + n);
  int soFar = a[0];
  ans[0] = a[0];
  for(int i = 1; i < n; i++) {
    int best = i;
    for(int j = i + 1; j < n; j++) {
      if(__gcd(soFar, a[best]) < __gcd(soFar, a[j])) {
        best = j;
      }
    }
    soFar = __gcd(soFar, a[best]);
    swap(a[i], a[best]);
  }
  // for(int i = 1; i < n; i++) {
  //   a[i] = __gcd(a[i], a[i - 1]);
  // }
  for(int i = 0; i < n; i++)
    cout << a[i] << " ";
  cout << endl;
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
