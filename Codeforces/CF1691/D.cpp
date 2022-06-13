#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;

const int N = 2e5 + 5;

int n;
int arr[N];
int nxt[N], prv[N], lf[N], rt[N];
long long pref[N];

ll sum(int l, int r) {
  return pref[r] - (l > 0 ? pref[l - 1] : 0);
}

bool check(int l, int r) {
  return max(arr[l], arr[r]) >= sum(l, r);
}

void solve() {
  cin >> n;
  pref[0] = 0;
  for(int i = 1; i <= n; i++) {
    cin >> arr[i];
    pref[i] = pref[i - 1] + arr[i];
  }
  stack<pair<int, int>> st;
  st.push({INT_MAX, n + 1});
  nxt[n + 1] = n + 1;
  rt[n + 1] = n + 1;
  for(int i = n; i >= 1; i--) {
    while(st.top().first <= arr[i]) {
      st.pop();
    }
    nxt[i] = st.top().second;
    st.push({arr[i], i});
    if(arr[i] > 0) rt[i] = i;
    else rt[i] = rt[i + 1];
  }
  while(sz(st)) st.pop();
  prv[0] = 0;
  st.push({INT_MAX, 0});
  lf[0] = 0;
  for(int i = 1; i <= n; i++) {
    while(st.top().first <= arr[i]) {
      st.pop();
    }
    prv[i] = st.top().second;
    st.push({arr[i], i});
    if(arr[i] > 0) lf[i] = i;
    else lf[i] = lf[i - 1];
  }
  while(sz(st)) st.pop();


  for(int i = 1; i <= n; i++) {
    if(arr[i] > 0) {
      int x = max(lf[i - 1], 0);
      if(!check(x, i)) {
        cout << "NO" << endl;
        return;
      }
      x = min(rt[i + 1], n);
      if(!check(i, x)) {
        cout << "NO" << endl;
        return;
      }
      x = max(prv[i], 0);
      if(!check(x, i)) {
        cout << "NO" << endl;
        return;
      }
      x = min(nxt[i], n);
      if(!check(i, x)) {
        cout << "NO" << endl;
        return;
      }
    }
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
