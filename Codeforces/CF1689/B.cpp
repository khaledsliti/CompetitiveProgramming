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

const int N = 1007;

int n;
int arr[N];

void solve() {
  cin >> n;
  vector<int> res(n);
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
    res[i] = i + 1;
  }
  if(n == 1) {
    cout << -1 << endl;
    return;
  }
  for(int i = 0; i < n; i++) {
    if(res[i] == arr[i]) {
      if(i + 1 < n) {
        swap(res[i], res[i + 1]);
      } else {
        swap(res[i - 1], res[i]);
      }
    }
  }
  for(int i = 0; i < n; i++) {
    cout << res[i] << " ";
  }
  cout << endl;
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
