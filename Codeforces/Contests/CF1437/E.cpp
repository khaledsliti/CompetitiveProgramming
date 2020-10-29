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

const int N = 5e5 + 5;
const int INF = 2e9;

int n;
vector<int> arr;
int fix[N];

int lis(vector<int>& a) {
  vector<int> t;
  for(int i = 0; i < sz(a); i++) {
    int idx = lower_bound(all(t), a[i] + 1) - begin(t);
    if(idx >= sz(t)) t.pb(a[i]);
    else t[idx] = a[i];
  }
  return sz(t);
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int k;
  cin >> n >> k;
  arr.resize(n + 2);
  arr[0] = -INF;
  for(int i = 1; i <= n; i++) {
    cin >> arr[i];
    arr[i] -= i;
  }
  arr[n + 1] = INF;
  vector<int> b;
  while(k-- > 0) {
    int p; cin >> p;
    b.push_back(p);
    fix[p] = 1;
  }
  fix[0] = fix[n + 1] = 1;
  for(int i = 1; i < sz(b); i++) {
    int j = b[i - 1], k = b[i];
    if(arr[k] < arr[j]) {
      cout << -1 << endl;
      return 0;
    }
  }
  int ans = 0;
  for(int i = 1; i <= n; i++) {
    if(!fix[i]) {
      int j = i;
      while(j <= n && !fix[j]) {
        j++;
      }
      vector<int> t;
      for(int k = i; k < j; k++) {
        if(arr[i - 1] <= arr[k] && arr[k] <= arr[j]) {
          t.pb(arr[k]);
        }
      }
      ans += j - i - lis(t);
      i = j;
    }
  }
  cout << ans << endl;
  return 0;
}