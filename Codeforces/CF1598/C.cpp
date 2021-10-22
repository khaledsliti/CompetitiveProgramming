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

const int N = 2e5 + 5;

int n;
int arr[N];

void solve() {
  cin >> n;
  long long s = 0;
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
    s += arr[i];
  }
  s *= 2;
  if(s % n != 0) {
    cout << 0 << endl;
    return;
  }
  s /= n;
  unordered_map<long long, int> fr;
  long long ans = 0;
  for(int i = 0; i < n; i++) {
    long long need = s - arr[i];
    ans += fr[need];
    fr[arr[i]]++;
  }
  cout << ans << endl;
}

/*

s / n = (s - a - b) / (n - 2)
s * (n - 2) = s * n - (a + b) * n
(a + b) * n = 2 * s
(a + b) = (2 * s) / n

*/

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
