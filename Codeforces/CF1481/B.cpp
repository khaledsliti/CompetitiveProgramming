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

const int N = 105;

int n, k;
int h[N];

void solve() {
  cin >> n >> k;
  for(int i = 0; i < n; i++) {
    cin >> h[i];
  }
  bool y = false;
  int last;
  for(int it = 0; it < k; it++) {
    int i = 0;
    while(i < n - 1 && h[i] >= h[i + 1]) {
      i++;
    }
    if(i >= n - 1) {
      y = true;
      break;
    } else {
      h[i]++;
      last = i;
    }
  }
  if(y) cout << -1 << endl;
  else cout << last + 1 << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int T;
  cin >> T;
  while(T--)
    solve();
  return 0;
}
