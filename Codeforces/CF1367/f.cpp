// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
typedef long long ll;

const int N = 2e5 + 5;

int n;
int arr[N], a[N];
int dp[N];

void solve() {
  cin >> n;
  map<int, int> f, l, fr;
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
    a[i] = arr[i];
    l[arr[i]] = i;
    if(!f.count(arr[i]))
      f[arr[i]] = i;
  }
  sort(a, a + n);
  map<int, int> nxt;
  for(int i = 1; i < n; i++) {
    if(a[i - 1] != a[i])
      nxt[a[i - 1]] = a[i];
  }
  map<int, int> pos;
  int best = 1;
  for(int i = n - 1; i >= 0; i--) {
    dp[i] = ++fr[arr[i]];
    // take next all
    if(nxt.count(arr[i]) && l[arr[i]] < f[nxt[arr[i]]]) {

    }
    // take some next
    if(nxt.count(arr[i]) && pos.count(nxt[arr[i]])) {

    }
    pos[arr[i]] = i;
  }
  cout << n - best << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) {
    solve();
  }
  return 0;
}
