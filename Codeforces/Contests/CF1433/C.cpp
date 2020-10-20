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

const int N = 3e5 + 5;

int n;
int arr[N];

void solve() {
  cin >> n;
  int mx = 0, mn = 2e9;
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
    mx = max(mx, arr[i]);
    mn = min(mn, arr[i]);
  }
  int idx = -1;
  for(int i = 0; i < n; i++) {
    if(arr[i] == mx && ((i > 0 && arr[i] > arr[i - 1]) || (i + 1 < n && arr[i] > arr[i + 1]))) {
      idx = i + 1;
      break;
    }
  }
  cout << idx << endl;
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
