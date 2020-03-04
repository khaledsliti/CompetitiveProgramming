// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 1e6 + 5;
const long long oo = 1e18;

int n, m, p;
pair<int, int> a[N];
pair<pair<int, int>, int> mons[N];
long long tmp[N];
long long st[4 * N];
long long lz[4 * N];

void build(int node, int s, int e) {
  if(s == e){
    st[node] = tmp[s];
    lz[node] = 0;
    return;
  }
  int l = 2 * node + 1;
  int r = 2 * node + 2;
  int mid = (s + e) / 2;
  build(l, s, mid);
  build(r, mid + 1, e);
  st[node] = max(st[l], st[r]);
  lz[node] = 0;
}

void push_dow(int cur, int s, int e) {
  if(lz[cur]) {
    st[cur] += lz[cur];
    if(s != e) {
      int l = 2 * cur + 1;
      int r = 2 * cur + 2;
      lz[l] += lz[cur];
      lz[r] += lz[cur];
    }
    lz[cur] = 0;
  }
}

void update(int cur, int s, int e, int i, int j, int val) {
  push_dow(cur, s, e);
  if(s > j || e < i) return;
  int l = 2 * cur + 1;
  int r = 2 * cur + 2;
  int mid = (s + e) / 2;
  if(s >= i && e <= j) {
    st[cur] += val;
    if(s != e){
      lz[l] += val;
      lz[r] += val;
    }
    return;
  }
  update(l, s, mid, i, j, val);
  update(r, mid + 1, e, i, j, val);
  st[cur] = max(st[l], st[r]);
  lz[cur] = 0;
}

int main()
{
  scanf("%d%d%d", &n, &m, &p);
  for(int i = 0 ; i < n ; i++) {
    scanf("%d%d", &a[i].first, &a[i].second);
  }
  for(int i = 0 ; i < N ; i++) {
    tmp[i] = -oo;
  }
  for(int i = 0 ; i < m ; i++) {
    int b, c;
    scanf("%d%d", &b, &c);
    tmp[b] = max(tmp[b], -1LL * c);
  }
  for(int i = 0 ; i < p ; i++) {
    scanf("%d%d%d", &mons[i].first.first, &mons[i].first.second, &mons[i].second);
  }
  sort(a, a + n, [](const pair<int, int>& a, const pair<int, int>& b){
    return a.first < b.first;
  });
  sort(mons, mons + p, [](const pair<pair<int, int>, int>& a, const pair<pair<int, int>, int>& b){
    return a.first < b.first;
  });
  build(0, 0, N - 1);
  int len = 0;
  long long ans = -2 * oo;
  for(int i = 0 ; i < n ; i++) {
    while(len < p && mons[len].first.first < a[i].first) {
      int pos = mons[len].first.second;
      int prof = mons[len].second;
      update(0, 0, N - 1, pos + 1, N - 1, prof);
      len++;
    }
    push_dow(0, 0, N - 1);
    ans = max(ans, st[0] - a[i].second);
  }
  cout << ans << endl;
  return 0;
}
