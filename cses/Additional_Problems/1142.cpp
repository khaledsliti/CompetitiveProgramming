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
int a[N], L[N], R[N];

int main()
{
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  stack<pair<int, int>> st;
  st.push({0, -1});
  for(int i = 0; i < n; i++) {
    while(st.top().first >= a[i])
      st.pop();
    L[i] = st.top().second + 1;
    st.push({a[i], i});
  }
  while(st.size()) {
    st.pop();
  }
  st.push({0, n});
  for(int i = n - 1; i >= 0; i--) {
    while(st.top().first >= a[i]) {
      st.pop();
    }
    R[i] = st.top().second - 1;
    st.push({a[i], i});
  }
  ll ans = 0;
  for(int i = 0; i < n; i++) {
    int width = R[i] - L[i] + 1;
    ans = max(ans, 1LL * width * a[i]);
  }
  cout << ans << endl;
  return 0;
}
