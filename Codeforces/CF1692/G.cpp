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

int n, k;
int arr[N];
int nxt[N];

void solve() {
  cin >> n >> k;
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  nxt[n - 1] = n - 1;
  for(int i = n - 2; i >= 0; i--) {
    if(arr[i] < 2 * arr[i + 1]) {
      nxt[i] = nxt[i + 1];
    } else {
      nxt[i] = i;
    }
  }
  int ans = 0;
  for(int i = 0; i < n; i++) {
    if(nxt[i] - i + 1 >= k + 1) {
      ans++;
    }
  }
  cout << ans << endl;
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
