#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;

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

const int N = 2e5 + 5;
const int L = 18;

struct Node {
  vector<int> odd, even;
};

int n;
int arr[N];
Node st[N << 2];

Node merge(const Node& a, const Node& b) {
  vector<pair<int, int>> tmp;
  for(auto x: a.odd) {
    tmp.push_back({x, 1});
  }
  for(auto x: a.even) {
    tmp.push_back({x, 0});
  }
  for(auto x: b.odd) {
    tmp.push_back({x, 1});
  }
  for(auto x: b.even) {
    tmp.push_back({x, 0});
  }
  sort(all(tmp));
  Node r;
  for(int i = 0; i < sz(tmp); i++) {
    int s = 0;
    int j = i;
    while(j < sz(tmp) && tmp[i].first == tmp[j].first) {
      s ^= tmp[j].second;
      j++;
    }
    if(s && sz(r.odd) < L) {
      r.odd.push_back(tmp[i].first);
    }
    if(!s && sz(r.even) < L) {
      r.even.push_back(tmp[i].first);
    }
    i = j - 1;
  }
  return r;
}

void build(int cur, int s, int e) {
  if(s == e) {
    st[cur].odd = {arr[s]};
    st[cur].even.clear();
    return;
  }
  int r = 2 * cur + 1;
  int l = 2 * cur + 2;
  int mid = (s + e) / 2;
  build(l, s, mid);
  build(r, mid + 1, e);
  st[cur] = merge(st[l], st[r]);
}

Node query(int cur, int s, int e, int i, int j) {
  if(s > j || e < i) {
    return Node{};
  }
  if (s >= i && e <= j) {
    return st[cur];
  }
  int r = 2 * cur + 1;
  int l = 2 * cur + 2;
  int mid = (s + e) / 2;
  return merge(query(l, s, mid, i, j), query(r, mid + 1, e, i, j));
}

int query(int l, int r) {
  auto node = query(0, 0, n - 1, l, r);
  // debug(l, r);
  // debug(node.odd);
  if(sz(node.odd)) {
    return node.odd[0];
  }
  return 0;
}

void solve() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  build(0, 0, n - 1);

  int q; cin >> q;
  int ans = 0;
  while(q--) {
    int a, b; cin >> a >> b;
    int l = ans ^ a;
    int r = ans ^ b;
    ans = query(--l, --r);
    cout << ans << endl;
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int T = 1;
  while(T--) {
    solve();
  }
  return 0;
}