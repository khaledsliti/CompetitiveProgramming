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

const int N = 2e5 + 5;

int n;
int arr[N];
vector<int> st[N << 2];

void merge(vector<int>& res, const vector<int>& a, const vector<int>& b) {
  res.insert(end(res), all(a));
  res.insert(end(res), all(b));
  sort(all(res));
}

void build(int cur, int s, int e) {
  if(s == e) {
    st[cur] = {arr[e]};
    return;
  }
  int mid = (s + e) >> 1;
  build(2 * cur + 1, s, mid);
  build(2 * cur + 2, mid + 1, e);
  merge(st[cur], st[2 * cur + 1], st[2 * cur + 2]);
}

int query(int cur, int s, int e, int i, int j, int x) {
  if(s > j || e < i) return 0;
  if(s >= i && e <= j) {
    return lower_bound(all(st[cur]), x + 1) - lower_bound(all(st[cur]), x);
  }
  int mid = (s + e) >> 1;
  return query(2 * cur + 1, s, mid, i, j, x) + query(2 * cur + 2, mid + 1, e, i, j, x);
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  build(0, 0, n - 1);
  int q;
  cin >> q;
  while(q--) {
    int l, r, x;
    cin >> l >> r >> x;
    cout << query(0, 0, n - 1, --l, --r, x) << endl;
  }
  return 0;
}
