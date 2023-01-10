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

  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(all(a));

  ll ans = 1;
  ll last = 0;
  for(int cur : a) {
    if (ans < cur) {
      break;
    }
    ans = last + cur + 1;
    last = ans - 1;
  }
  cout << ans << endl;
  return 0;
}


/*
ans - cur > last
ans > last + cur

*/