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

const int N = 1004;

int n;
pair<int, int> arr[N];
int cnt[N];

void solve() {
  cin >> n;
  for (int i = 0; i <= n; i++) {
    cnt[i] = 0;
  }
  for (int i = 0; i < n; i++) {
    cin >> arr[i].first >> arr[i].second;
    --arr[i].first, --arr[i].second;
    for (int j = arr[i].first; j <= arr[i].second; j++) {
      cnt[j]++;
    }
  }

  for (int i = 0; i < n; i++) {
    int l = arr[i].first;
    int r = arr[i].second;
    int at = l;
    for (int j = l + 1; j <= r; j++) {
      if (cnt[at] > cnt[j]) {
        at = j;
      }
    }
    cout << l + 1 << " " << r + 1 << " " << at + 1 << endl;
  }
  cout << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int T;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
