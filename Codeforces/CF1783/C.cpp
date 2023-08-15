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

const int N = 5e5 + 5;
const int MAX = 1001;

int n, m;
int arr[N];
int ord[N];

bool check(int p, int m) {
  if (m >= arr[p - 1]) {
    int tmp = m - arr[p - 1];
    int cnt = 1;
    for (int i = 0; i < n; i++) {
      if (p - 1 == ord[i]) {
        continue;
      }
      if (tmp < arr[ord[i]]) {
        break;
      }
      cnt++;
      tmp -= arr[ord[i]];
    }
    if (cnt >= p - 1) {
      return true;
    }
  }

  int tmp = m;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (tmp < arr[ord[i]]) {
      break;
    }
    cnt++;
    tmp -= arr[ord[i]];
  }

  if (cnt >= p) {
    return true;
  }

  return false;
}

void solve() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    int a; cin >> a;
    arr[i] = a;
    ord[i] = i;
  }
  sort(ord, ord + n, [&](int a, int b) {
    return arr[a] < arr[b];
  });

  // for (int i = 1; i <= n; i++) {
  //   cout << i << " " << check(i, m) << endl;
  // }
  int low = 1, high = n, best = 0;
  while (low <= high) {
    int mid = (low + high) >> 1;
    if (check(mid, m)) {
      best = mid;
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  // cout << best << endl;
  cout << n - best + 1 << endl;
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
