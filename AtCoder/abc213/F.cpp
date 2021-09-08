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

typedef long long ll;

const int A = 128;
const int N = 200005;

int n;
char s[N];
int suff[N], t_suff[N], rnk[N], rnk_start[N], t_rnk[N];
int lcp[N];

int* head = t_rnk, *nxt = lcp;

struct Comparator {
  int len;
  Comparator(int len): len(len) {}
  bool operator()(const int& i, const int& j) const {
    return rnk[i] < rnk[j] || (rnk[i] == rnk[j] && rnk[i + len] < rnk[j + len]);
  }
};

void build_suff_array() {
  int len;
  memset(head, -1, A * sizeof(head));
  for(len = 0; !len || s[len - 1]; len++) {
    nxt[len] = head[s[len]];
    head[s[len]] = len;
  }
  int cur_rnk = 0, j = 0;
  for(int i = 0; i < A; i++) {
    if(head[i] != -1) {
      rnk_start[cur_rnk] = j;
      for(int k = head[i]; ~k; k = nxt[k]) {
        suff[j++] = k;
        rnk[k] = cur_rnk;
      }
      cur_rnk++;
    }
  }
  t_suff[0] = suff[0];
  t_rnk[0] = 0;
  for(int width = 1; t_rnk[len - 1] != len - 1; width <<= 1) {
    Comparator isSmaller(width);
    for(int i = 0; i < len; i++) {
      j = suff[i] - width;
      if(j < 0) continue;
      t_suff[rnk_start[rnk[j]]++] = j;
    }
    for(int i = 1; i < len; i++) {
      bool nw_rnk =  isSmaller(t_suff[i - 1], t_suff[i]);
      t_rnk[i] = t_rnk[i - 1] + nw_rnk;
      if(nw_rnk) rnk_start[t_rnk[i]] = i;
    }
    for(int i = 0; i < len; i++) {
      suff[i] = t_suff[i];
      rnk[suff[i]] = t_rnk[i];
    }
  }
}

void build_lcp() {
  for(int i = 0, len = 0; s[i]; i++) {
    int j = suff[rnk[i] - 1];
    while(s[i + len] == s[j + len]) len++;
    lcp[rnk[i]] = len;
    if(len) len--;
  }
}

/*******************************************/

struct Node {
  ll sum, toAdd;
  Node() = default;
  Node(ll s, ll ta): sum(s), toAdd(ta) {}
};

Node st[N << 2];

inline int L(int x) { return (x << 1) + 1; }
inline int R(int x) { return (x << 1) + 2; }
inline int Mid(int s, int e) { return s + (e - s) / 2; }

Node merge(const Node& a, const Node& b) {
  return Node(a.sum + b.sum, 0);
}

void push_down(int cur, int s, int e) {
  if(st[cur].toAdd != 0) {
    st[cur].sum += st[cur].toAdd * (e - s + 1);
    if(s != e) {
      st[L(cur)].toAdd += st[cur].toAdd;
      st[R(cur)].toAdd += st[cur].toAdd;
    }
    st[cur].toAdd = 0;
  }
}

void increase(int cur, int s, int e, int i, int j, int x) {
  push_down(cur, s, e);
  if(s > j || e < i) return;
  if(s >= i && e <= j) {
    st[cur].toAdd += x;
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
  if(s > j || e < i) return Node(0, 0);
  if(s >= i && e <= j) return st[cur];
  int mid = Mid(s, e);
  return merge(query(L(cur), s, mid, i, j), query(R(cur), mid + 1, e, i, j));
}

/*******************************************/

vector<pair<int, int>> queries;

void process() {
  for(int i = 0; i < sz(queries); i++) {
    int l = queries[i].first, r = queries[i].second;
    increase(0, 0, n - 1, l, r, 1);
    if(l > 0) {
      increase(0, 0, n - 1, l - 1, l - 1, -(r - l + 1));
    }
  }
}

int main()
{
  scanf("%d%s", &n, s);

  build_suff_array();
  build_lcp();

  for(int i = 0; i <= n; i++) {
    cout << lcp[i] << " - " << suff[i] << " " << (s + suff[i]) << endl;
  }

  for(int i = 1; i <= n; i++) {
    if(lcp[i] > 0) {
      queries.push_back({suff[i], suff[i] + lcp[i] - 1});
      queries.push_back({suff[i - 1], suff[i - 1] + lcp[i] - 1});
    }
  }

  debug(queries);

  process();

  for(int i = 0; i < n; i++) {
    printf("%lld\n", n - i + query(0, 0, n - 1, i, n - 1).sum);
  }
  
  return 0;
}
