#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;

const int N = 2e5  + 5;

int n;
int arr[N];
int ex[N];
int mex[N];

void solve() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  int at = 0;
  for(int i = n - 1; i >= 0; i--) {
    ex[arr[i]] = 1;
    while(ex[at]) at++;
    mex[i] = at;
  }
  for(int i = 0; i < n; i++) {
    ex[arr[i]] = 0;
  }
  vector<int> ans;
  for(int i = 0; i < n; i++) {
    int j = i;
    int nw = 0;
    while(true) {
      ex[arr[j]] = 1;
      while(ex[nw]) nw++;
      if(nw == mex[i]) {
        break;
      }
      j++;
    }
    ans.push_back(mex[i]);
    for(int k = i; k <= j; k++) {
      ex[arr[k]] = 0;
    }
    i = j;
  }
  cout << sz(ans) << endl;
  for(int x: ans) cout << x << " "; cout << endl;
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
