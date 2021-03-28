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

const int N = 1e5 + 5;
int n;
int arr[N], mx[N];

void solve() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
    mx[i] = i;
    if(i > 0 && arr[mx[i]] < arr[mx[i - 1]]) {
      mx[i] = mx[i - 1];
    }
  }
  int i = n - 1;
  while(i >= 0) {
    int j = mx[i];
    for(int k = j; k <= i; k++)
      cout << arr[k] << " ";
    i = j - 1;
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
