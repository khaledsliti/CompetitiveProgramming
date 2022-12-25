// RedStone
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
const int L = 20;

struct Node;
typedef Node* pnode;

struct Node {
  int val, idx;
  Node *left, *right;
  Node(int val, int idx): val(val), idx(idx), left(nullptr), right(nullptr) {}
  bool operator<(const Node& rhs) const {
    return mp(val, idx) < mp(rhs.val, rhs.idx);
  }
};

int n, m, q;
vector<pair<int, int>> el[N];
array<int, 4> qr[N];
int dp[N][L];

pnode tree;

pair<int, int> get(pnode cur) {
  return cur == nullptr ? mp(0, 0) : mp(cur->val, cur->idx);
}

void merge(pnode cur, pnode a, pnode b) {
  auto aa = get(a), bb = get(b);
  if(aa >= bb) {
    tie(cur->val, cur->idx) = aa;
  } else {
    tie(cur->val, cur->idx) = bb;
  }
}

void update(pnode& cur, int s, int e, int idx, int val, int at) {
  if(idx < s || idx > e) return;
  if(cur == nullptr) cur = new Node(0, 0);
  if(s == e) {
    merge(cur, cur, new Node(val, at));
    return;
  }
  int mid = (s + e) >> 1;
  update(cur->left, s, mid, idx, val, at);
  update(cur->right, mid + 1, e, idx, val, at);
  merge(cur, cur->left, cur->right);
}



pair<int, int> query_max(pnode cur, int s, int e, int i, int j) {
  if(s > j || e < i || cur == nullptr) return {0, 0};
  if(s >= i && e <= j) return get(cur);
  int mid = (s + e) >> 1;
  return max(query_max(cur->left, s, mid, i, j), query_max(cur->right, mid + 1, e, i, j));
}

vector<pair<int, int>> merge(vector<pair<int, int>> a) {
  vector<pair<int, int>> r;
  sort(all(a));
  for(int i = 0; i < sz(a); i++) {
    int j = i;
    int mx = a[i].second;
    while(j < sz(a) && a[j].first <= mx) {
      mx = max(mx, a[j].second);
      j++;
    }
    r.push_back({a[i].first, mx});
    i = j - 1;
  }
  return r;
}

int jump(int i, int k) {
  k--;
  for(int j = 0; j < L; j++) {
    if(k & (1 << j)) {
      i = dp[i][j];
    }
  }
  return dp[i][0];
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m >> q;
  for(int i = 0; i < m; i++) {
    int a, b, c; cin >> a >> b >> c;
    el[--a].push_back({b, c});
  }
  for(int i = 0; i < q; i++) {
    for(int j = 0; j < 4; j++) {
      cin >> qr[i][j];
    }
    el[--qr[i][0]].push_back({qr[i][1], qr[i][1]});
    el[--qr[i][2]].push_back({qr[i][3], qr[i][3]});
  }
  vector<array<int, 3>> all_el;
  for(int i = 0; i < n; i++) {
    el[i] = merge(el[i]);
    for(auto s: el[i]) {
      all_el.push_back({s.first, s.second, i});
    }
  }
  for(int i = 0; i < sz(all_el); i++) {
    update(tree, 0, 1e9, all_el[i][0], all_el[i][1], i);
  }
  for(int i = 0; i < sz(all_el); i++) {
    auto tmp = query_max(tree, 0, 1e9, all_el[i][0], all_el[i][1]);
    dp[i][0] = tmp.second;
  }

  for(int i = 0; i < q; i++) {
    
  }


  return 0;
}
