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
const int INF = 1e9;


int n;
int arr[N];
long long pref[N];

void solve() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  int x; cin >> x;
  for(int i = 0; i < n; i++) {
    arr[i] -= x;
  }
  int ans = 0;
  for(int i = 0; i < n; i++) {
    int j = i;
    long long mx = -1e12;
    long long sum = 0;
    while(j < n) {
      sum += arr[j];
      if(sum - mx < 0) {
        break;
      }
      mx = max(mx, sum - arr[j]);
      j++;
    }
    ans += j - i;
    i = j;
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
