// https://www.spoj.com/problems/MKTHNUM/
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
typedef long long ll;

#define L(x) (2 * (x) + 1)
#define R(x) (2 * (x) + 2)

const int N = 100001;

int n, q;
int arr[N];
vector<int> st[N << 2];

void merge(const vector<int>& a, const vector<int>& b, vector<int>& r) {
  int i = 0, j = 0;
  while(i < sz(a) && j < sz(b)) {
    if(a[i] < b[j]) r.push_back(a[i++]);
    else r.push_back(b[j++]);
  }
  while(i < sz(a))
    r.push_back(a[i++]);
  while(j < sz(b))
    r.push_back(b[j++]);
}

void build(int cur, int s, int e) {
  if(s == e) {
    st[cur].push_back(arr[s]);
    return;
  }
  int mid = (s + e) / 2;
  int l = 2 * cur + 1;
  int r = 2 * cur + 2;
  build(l, s, mid);
  build(r, mid + 1, e);
  merge(st[l], st[r], st[cur]);
}

int query(int cur, int s, int e, int i, int j, int val) {
  if(s > j || e < i) return 0;
  if(s >= i && e <= j) {
    return upper_bound(st[cur].begin(), st[cur].end(), val) - st[cur].begin();
  }
  int mid = (s + e) / 2;
  int l = 2 * cur + 1;
  int r = 2 * cur + 2;
  return query(l, s, mid, i, j, val) + query(r, mid + 1, e, i, j, val);
}

void print(int cur, int s, int e) {
  cout << cur << " :";
  for(int x : st[cur])
    cout << " " << x;
  cout << endl;
  if(s != e) {
    int mid = (s + e) / 2;
    print(L(cur), s, mid);
    print(R(cur), mid + 1, e);
  }
}

int main()
{
  scanf("%d%d", &n, &q);
  int lo = 1e9, hi = 0;
  for(int i = 0; i < n; i++) {
    scanf("%d", arr + i);
    lo = min(lo, arr[i]);
    hi = max(hi, arr[i]);
  }
  build(0, 0, n - 1);
  while(q--) {
    int l, r, k;
    scanf("%d%d%d", &l, &r, &k);
    --l, --r;
    int s = lo, e = hi, ans;
    while(s <= e) {
      int mid = (s + e) / 2;
      if(query(0, 0, n - 1, l, r, mid) >= k) {
        ans = mid;
        e = mid - 1;
      } else {
        s = mid + 1;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
