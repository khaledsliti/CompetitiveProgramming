// RedStone
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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  long long l, n1, n2;
  cin >> l >> n1 >> n2;
  vector<pair<long long, long long>> a(n1), b(n2);
  for (int i = 0; i < n1; i++) {
    cin >> a[i].first >> a[i].second;
  }
  for (int i = 0; i < n2; i++) {
    cin >> b[i].first >> b[i].second;
  }

  long long ans = 0;
  int i = 0, j = 0;
  while (i < n1 && j < n2) {
    long long mn = min(a[i].second, b[j].second);
    if (a[i].first == b[j].first) {
      ans += mn;
    }
    if (a[i].second > b[j].second) {
      a[i].second -= mn;
      j++;
      continue;
    }
    if (a[i].second < b[j].second) {
      i++;
      b[j].second -= mn;
      continue;
    }
    i++;
    j++;
  }
  cout << ans << endl;
  return 0;
}
