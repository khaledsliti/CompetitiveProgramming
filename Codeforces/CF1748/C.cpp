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
long long pref[N];

void solve() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
    pref[i] = arr[i];
    if(i > 0) {
      pref[i] += pref[i - 1];
    }
  }
  int ans = 0;
  int end = n;
  map<long long, int> fr;
  for(int i = n - 1; i >= 0; i--) {
    fr[pref[i]]++;
    if(arr[i] == 0) {
      int mx = 0;
      for(auto x: fr) {
        mx = max(mx, x.second);
      }
      ans += mx;
      fr.clear();
      end = i;
    }
  }
  for(int i = 0; i < end; i++) {
    ans += pref[i] == 0;
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
