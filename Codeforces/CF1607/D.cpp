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
int arr[N];
string col;

void solve() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  cin >> col;
  vector<int> blue, red;
  for(int i = 0; i < n; i++) {
    if(col[i] == 'B') {
      blue.push_back(arr[i]);
    } else {
      red.push_back(arr[i]);
    }
  }
  sort(rall(blue));
  sort(rall(red));
  for(int i = 1; i <= n; i++) {
    while(sz(blue) && blue.back() < i)
      blue.pop_back();
    if(sz(blue)) {
      blue.pop_back();
      continue;
    }
    if(!sz(red) || red.back() > i) {
      cout << "NO" << endl;
      return;
    }
    red.pop_back();
  }
  cout << "YES" << endl;
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
