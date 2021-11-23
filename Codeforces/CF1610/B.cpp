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

bool check(const vector<int>& tmp) {
  for(int i = 0; i < sz(tmp); i++) {
    if(tmp[i] != tmp[sz(tmp) - 1 - i]) {
      return false;
    }
  }
  return true;
}

void solve() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  int i = 0, j = n - 1;
  while(i < j) {
    if(arr[i] != arr[j]) {
      for(int cur: {arr[i], arr[j]}) {
        vector<int> tmp;
        for(int k = 0; k < n; k++) {
          if(arr[k] != cur) {
            tmp.pb(arr[k]);
          }
        }
        if(check(tmp)) {
          cout << "YES" << endl;
          return;
        }
      }
      cout << "NO" << endl;
      return;
    }
    i++, j--;
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
