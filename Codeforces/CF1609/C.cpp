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

const int V = 1e6 + 5;
const int N = 2e5 + 5;

int isp[V];
int n, e;
int arr[N];

long long calc(const vector<int>& a) {
  long long ans = 0;
  for(int i = 0; i < sz(a); i++) {
    if(isp[a[i]]) {
      int l = i - 1; while(l >= 0 && a[l] == 1) l--;
      int r = i + 1; while(r < sz(a) && a[r] == 1) r++;
      l = i - l - 1;
      r = r - i - 1;
      ans += 1LL * (l + 1) * (r + 1) - 1;
    }
  }
  return ans;
}

void solve() {
  cin >> n >> e;
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  long long ans = 0;
  for(int st = 0; st < e; st++) {
    vector<int> a;
    for(int i = st; i < n; i += e) {
      a.push_back(arr[i]);
    }
    ans += calc(a);
  }
  cout << ans << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  for(int i = 2; i < V; i++) {
    isp[i] = 1;
  }
  for(int i = 2; i < V; i++) {
    if(isp[i]) {
      for(int j = i + i; j < V; j += i) {
        isp[j] = 0;
      }
    }
  }

  int T;
  cin >> T;
  while(T--) {
    solve();
  }
  return 0;
}
