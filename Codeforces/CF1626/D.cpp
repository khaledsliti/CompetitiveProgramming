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
const int Log = 18;

int n;
int arr[N];
vector<int> val;
int miss[N], L[N], R[N];

int calc(int i, int j) {
  j = min(j, n);
  return miss[i] + miss[j - i] + miss[n - j];
}

void solve() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sort(arr, arr + n);
  L[n] = n;
  for(int i = 0; i < n; i++) {
    if(i == 0 || arr[i] != arr[i - 1]) L[i] = i;
    else L[i] = L[i - 1];
  }
  R[n] = n;
  for(int i = n - 1; i >= 0; i--) {
    if(i == n - 1 || arr[i] != arr[i + 1]) R[i] = i;
    else R[i] = R[i + 1];
  }
  int ans = 1e9;
  for(int i = 0; i < n; i++) {
    if(i == 0 || arr[i] != arr[i - 1]) {
      // start from i
      for(int mid: val) {
        int j = i + mid;
        if(j <= n && L[j] > i) {
          ans = min(ans, calc(i, L[j]));
        }
        if(j <= n && R[j] + 1 <= n) {
          ans = min(ans, calc(i, R[j] + 1));
        }
        j = n - mid;
        if(j < n && j >= 0 && L[j] > i) {
          ans = min(ans, calc(i, L[j]));
        }
        if(j < n && j >= 0 && R[j] + 1 < n) {
          ans = min(ans, calc(i, R[j] + 1));
        }
      }
    }
  }
  cout << ans << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  for(int i = 0; i <= Log; i++) {
    val.push_back(1 << i);
  }

  for(int i = 0; i < N; i++) {
    miss[i] = *lower_bound(all(val), i) - i;
  }

  int T;
  cin >> T;
  while(T--) {
    solve();
  }
  return 0;
}
