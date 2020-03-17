// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

// Region Debug
string to_string(const string &s) {
  return '"' + s + '"';
}

string to_string(const char* s) {
  return to_string((string) s);
}

string to_string(bool b) {
  return (b ? "true" : "false");
}

template<typename A, typename B>
string to_string(const pair<A, B>& p);

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);

template<typename T>
string to_string(const vector<T>& v) {
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (i > 0)
      res += ", ";
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}

template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}

template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first)
      res += ", ";
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}

template<typename A, typename B>
string to_string(const pair<A, B>& p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}

#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
// End Region

const int N = 1e5 + 5;

struct query {
  int type, idx, pos, y;
  bool operator<(const query& rhs) const {
    return pos < rhs.pos;
  }
};

struct node {
  int val;
  node *l, *r;
  node() : val(0), l(NULL), r(NULL) {}
};

typedef node* pNode;

int n, q, mx;
int arr[N];
vector<query> qr;
int ans[N];

node* getNewNode() {
  return new node();
}

void push_down(pNode& cur, int s, int e) {
  if(cur && cur->val > 0 && e != s) {
    if(!cur->l) cur->l = getNewNode();
    cur->l->val += cur->val;
    if(!cur->r) cur->r = getNewNode();
    cur->r->val += cur->val;
    cur->val = 0;
  }
}

void add(pNode& cur, int i, int j, int s, int e) {
  if(s > j || e < i) return;
  if(!cur) cur = getNewNode();
  push_down(cur, s, e);
  if(s >= i && e <= j) {
    cur->val++;
    push_down(cur, s, e);
    return;
  }
  int mid = (s + e) / 2;
  add(cur->l, i, j, s, mid);
  add(cur->r, i, j, mid + 1, e);
}

int get(pNode& cur, int i, int s, int e) {
  if(s > i || e < i || !cur) return 0;
  push_down(cur, s, e);
  if(s == e) return cur->val;
  int mid = (s + e) / 2;
  return get(cur->l, i, s, mid) + get(cur->r, i, mid + 1, e);
}

void format(map<int, int>& values) {
  mx = 0;
  for(auto& x : values)
    x.second = ++mx;
  for(int i = 0 ; i < n ; i++)
    arr[i] = values[arr[i]];
  for(int i = 0 ; i < sz(qr) ; i++) {
    qr[i].y = values[qr[i].y];
  }
}

void solve() {
  node* treeRoot = getNewNode();
  map<int, int> values;
  scanf("%d%d", &n, &q);
  for(int i = 0 ; i < n ; i++) {
    scanf("%d", &arr[i]);
    values[arr[i]];
  }
  qr.clear();
  for(int i = 0 ; i < q ; i++) {
    int l, r, y;
    scanf("%d%d%d", &l, &r, &y);
    values[y];
    if(l > 1) qr.push_back({0, i, l - 2, y});
    qr.push_back({1, i, r - 2, y});
    ans[i] = 0;
  }
  format(values);
  sort(all(qr));
  int j = 0;
  for(int i = 0 ; i + 1 < n ; i++) {
    int l = min(arr[i], arr[i + 1]);
    int r = max(arr[i], arr[i + 1]);
    add(treeRoot, l, r, 1, mx);
    while(j < sz(qr) && qr[j].pos == i) {
      int idx = qr[j].idx;
      if(qr[j].type == 0) ans[idx] -= get(treeRoot, qr[j].y, 1, mx);
      else ans[idx] += get(treeRoot, qr[j].y, 1, mx);
      j++;
    }
  }
  for(int i = 0 ; i < q ; i++)
    printf("%d\n", ans[i]);
}

int main()
{
  int T;
  scanf("%d", &T);
  while(T--) {
    solve();
  }
  return 0;
}
