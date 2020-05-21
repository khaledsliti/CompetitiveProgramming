// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 1e5 + 5;

int n;
int p[N];
int ans[N], peek[N];
pair<int, int> st[N << 2];

pair<int, int> merge(pair<int, int> a, pair<int, int> b) {
  return { a.first + b.first, a.first > 0 ? a.second : b.second };
}

pair<int, int> query(int cur, int s, int e, int i, int j) {
  if(s > j || e < i) return {0, 0};
  if(s >= i && e <= j) return st[cur];
  int mid = (s + e) / 2;
  int l = 2 * cur + 1;
  int r = 2 * cur + 2;
  return merge(query(l, s, mid, i, j), query(r, mid + 1, e, i, j));
}

void update(int cur, int s, int e, int idx) {
  if(s > idx || e < idx) return;
  if(s == e) return void(st[cur] = {1, s});
  int mid = (s + e) / 2;
  int l = 2 * cur + 1;
  int r = 2 * cur + 2;
  update(l, s , mid, idx);
  update(r, mid + 1, e, idx);
  st[cur] = merge(st[l], st[r]);
}

int main()
{
  scanf("%d", &n);
  for(int i = 0 ; i < n ; i++)
    scanf("%d", &p[i]);
  int peeks = 0;
  for(int i = 0 ; i < n ; i++) {
    pair<int, int> cur = query(0, 1, n, p[i], n);
    if(cur.first == 1)
      ans[cur.second]++;
    else if(cur.first == 0)
      peek[p[i]] = 1, peeks++;
    update(0, 1, n, p[i]);
  }
  int best = -1, At = -1;
  for(int i = 1 ; i <= n ; i++) {
    int cur = peeks - peek[i] + ans[i];
    if(cur > best) {
      best = cur;
      At = i;
    }
  }
  cout << At << endl;
  return 0;
}
