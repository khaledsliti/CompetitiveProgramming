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
int arr[N], ok[N];

void solve() {
  cin >> n;
  long long ans = 0;
  for(int i = 1; i <= n; i++) {
    cin >> arr[i];
    ok[i] = arr[i] < i;
    if(ok[i]) {
      ans += ok[max(0, arr[i] - 1)];
    }
    ok[i] += ok[i - 1];
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
/*
1 2 3 4 5 6 7 8
1 1 2 3 8 2 1 4
0 1 1 1 0 1 1 1
*/