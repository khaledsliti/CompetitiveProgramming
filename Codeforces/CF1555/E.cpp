// Guess Who's Back
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

const int N = 3e5 + 5;
const int V = 1e6 + 5;

struct Seg {
  int l, r;
  int cost;
  bool operator<(const Seg& rhs) const {
    return cost > rhs.cost;
  }
};

struct Node {
  int val;
  int delta;
  Node() = default;
  Node(int val): val(val), delta(0) {}
};


int n, m;
Seg arr[N];
Node st[V << 2];


inline int L(int x) { return (x << 1) + 1; }
inline int R(int x) { return (x << 1) + 2; }
inline int Mid(int s, int e) { return s + (e - s) / 2; }

Node merge(const Node& a, const Node& b) {
  return Node(min(a.val, b.val));
}

void push_down(int cur, int s, int e) {
  if(st[cur].delta != 0) {
    st[cur].val += st[cur].delta;
    if(s != e) {
      st[L(cur)].delta += st[cur].delta;
      st[R(cur)].delta += st[cur].delta;
    }
    st[cur].delta = 0;
  }
}

void increase(int cur, int s, int e, int i, int j, int x) {
  push_down(cur, s, e);
  if(s > j || e < i) return;
  if(s >= i && e <= j) {
    st[cur].delta += x;
    push_down(cur, s, e);
    return;
  }
  int mid = Mid(s, e);
  increase(L(cur), s, mid, i, j, x);
  increase(R(cur), mid + 1, e, i, j, x);
  st[cur] = merge(st[L(cur)], st[R(cur)]);
}

Node query(int cur, int s, int e, int i, int j) {
  push_down(cur, s, e);
  if(s > j || e < i) return Node(0);
  if(s >= i && e <= j) return st[cur];
  int mid = Mid(s, e);
  return merge(query(L(cur), s, mid, i, j), query(R(cur), mid + 1, e, i, j));
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    cin >> arr[i].l >> arr[i].r >> arr[i].cost;
    arr[i].l--;
    arr[i].r--;
  }
  sort(arr, arr + n);
  reverse(arr, arr + n);

  // for(int i = 0; i < n; i++) {
  //   cout << arr[i].l << " " << arr[i].r << " " << arr[i].cost << endl;
  // }

  int ans = INT_MAX;
  int j = n - 1;

  for(int i = n - 1; i >= 0; i--) {
    increase(0, 0, m - 2, arr[i].l, arr[i].r - 1, 1);

    while(j > i) {
      Seg cur = arr[j];
      increase(0, 0, m - 2, cur.l, cur.r - 1, -1);
      if(query(0, 0, m - 2, 0, m - 2).val == 0) {
        increase(0, 0, m - 2, cur.l, cur.r - 1, 1);
        break;
      }
      j--;
    }

    if(query(0, 0, m - 2, 0, m - 2).val > 0) {
      ans = min(ans, arr[j].cost - arr[i].cost);
    }
  }

  cout << ans << endl;
  return 0;
}
