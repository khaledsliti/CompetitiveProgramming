// We only fail when we stop trying
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
int K[N], L[N], R[N];
vector<int> pos[N];
int st[N << 2];
int nxtL[N], nxtR[N];
int pos_camel[N];

int diff(int idx) {
  return abs(L[idx] - R[idx]);
}

int fl(int x) {
  return nxtL[x] == x ? x : nxtL[x] = fl(nxtL[x]);
}

int fr(int x) {
  return nxtR[x] == x ? x : nxtR[x] = fr(nxtR[x]);
}

int merge(int i, int j) {
  if(i == -1) return j;
  if(j == -1) return i;
  if(diff(i) <= diff(j))
    return i;
  return j;
}

void build(int cur, int s, int e) {
  st[cur] = -1;
  if(s != e) {
    int l = 2 * cur + 1;
    int r = 2 * cur + 2;
    int mid = (s + e) / 2;
    build(l, s, mid);
    build(r, mid + 1, e);
  }
}

void update(int cur, int s, int e, int pos, int idx) {
  if(pos < s || pos > e) return;
  if(s == e) {
    st[cur] = idx;
    return;
  }
  int l = 2 * cur + 1;
  int r = 2 * cur + 2;
  int mid = (s + e) / 2;
  update(l, s, mid, pos, idx);
  update(r, mid + 1, e, pos, idx);
  st[cur] = merge(st[l], st[r]);
}

int query(int cur, int s, int e, int i, int j) {
  if(s > j || e < i) return -1;
  if(s >= i && e <= j) return st[cur];
  int l = 2 * cur + 1;
  int r = 2 * cur + 2;
  int mid = (s + e) / 2;
  return merge(query(l, s, mid, i, j), query(r, mid + 1, e, i, j));
}

void solve() {
  cin >> n;
  for(int i = 0; i <= n; i++) {
    pos[i].clear();
  }
  ll ans = 0;
  for(int i = 0; i < n; i++) {
    cin >> K[i] >> L[i] >> R[i];
    --K[i];
    if(L[i] == R[i]) ans += L[i];
    else if(L[i] > R[i]) pos[K[i]].push_back(i);
    else pos[K[i + 1]].push_back(i);
  }
  build(0, 0, n - 1);
  for(int i = 0; i <= n + 1; i++)
    nxtL[i] = nxtR[i] = i;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < sz(pos[i]); j++) {
      int cur = pos[i][j];
      if(L[cur] > R[cur]) { // prefer left
        int idx = fl(i + 1) - 1;
        if(idx < 0) {
          int lowest = query(0, 0, n - 1, 0, i);
          if(diff(lowest) < diff(cur)) { // update
            ans -= diff(lowest) - L[cur];
            update(0, 0, n - 1, pos_camel[lowest], cur);
            pos_camel[cur] = pos_camel[lowest];
          } else {
            ans += R[cur];
          }
        } else {
          ans += L[cur];
          update(0, 0, n - 1, idx, cur);
          nxtL[idx + 1] = idx;
          nxtR[idx + 1] = idx + 2;
          pos_camel[cur] = idx;
        }
      } else if(L[cur] < R[cur]) {
        int idx = fr(i + 1) - 1;
        if(idx >= n) {
          int lowest = query(0, 0, n - 1, i, n - 1);
          if(diff(lowest) < diff(cur)) { // update
            ans -= diff(lowest) - R[cur];
            update(0, 0, n - 1, pos_camel[lowest], cur);
            pos_camel[cur] = pos_camel[lowest];
          } else {
            ans += L[cur];
          }
        } else {
          ans += R[cur];
          update(0, 0, n - 1, idx, cur);
          nxtL[idx + 1] = idx;
          nxtR[idx + 1] = idx + 2;
          pos_camel[cur] = idx;
        }
      }
    }
  }
  cout << ans << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--)
    solve();
  return 0;
}
