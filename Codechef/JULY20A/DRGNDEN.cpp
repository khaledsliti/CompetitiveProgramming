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

int n, q;
int h[N], a[N];
int parL[N], parR[N];

struct TreeData {
  // Intervals data
  int st[N], en[N], cur_num;
  ll bit[N];
  vector<int> g[N];

  void add(int idx, ll val) {
    for(int i = idx; i < N; i += i & -i)
      bit[i] += val;
  }

  void add(int a, int b, ll val) {
    add(a, val);
    add(b + 1, -val);
  }

  ll query(int idx) {
    ll r = 0;
    for(int i = idx; i > 0; i -= i & -i)
      r += bit[i];
    return r;
  }

  void dfs(int u) {
    st[u] = cur_num++;
    for(int v: g[u]) {
      dfs(v);
    }
    en[u] = cur_num - 1;
  }

  void process(int* par) {
    for(int i = 0; i < n; i++)
      if(~par[i])
        g[par[i]].pb(i);
    cur_num = 0;
    for(int i = 0; i < n; i++)
      if(par[i] == -1) {
        dfs(i);
      }
    memset(bit, 0, sizeof(bit));
    for(int i = 0; i < n; i++) {
      int l = st[i], r = en[i];
      add(l + 1, r + 1, a[i]);
    }
  }

  void updateNode(int u, int diff) {
    add(st[u] + 1, en[u] + 1, diff);
  }

  ll answer(int fr, int to) {
    if(st[fr] < st[to] || en[fr] > en[to])
      return -1;
    return a[to] + query(st[fr] + 1) - query(st[to] + 1);
  }
};

TreeData leftTree, rightTree;


void build() {
  for(int i = 0; i < n; i++)
    parL[i] = parR[i] = -1;
  stack<pair<int, int>> st;
  for(int i = n - 1; i >= 0; i--) {
    while(st.empty() == false && st.top().first <= h[i]) {
      st.pop();
    }
    if(st.empty() == false)
      parR[i] = st.top().second;
    st.push({h[i], i});
  }
  while(st.empty() == false)
    st.pop();
  for(int i = 0; i < n; i++) {
    while(st.empty() == false  && st.top().first <= h[i])
      st.pop();
    if(st.empty() == false)
      parL[i] = st.top().second;
    st.push({h[i], i});
  }
}

int main()
{
  scanf("%d%d", &n, &q);
  for(int i = 0; i < n; i++) {
    scanf("%d", h + i);
  }
  for(int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  build();
  rightTree.process(parR);
  leftTree.process(parL);
  while(q--) {
    int t;
    scanf("%d", &t);
    if(t == 1) {
      int u, k;
      scanf("%d%d", &u, &k);
      --u;
      int diff = k - a[u];
      leftTree.updateNode(u, diff);
      rightTree.updateNode(u, diff);
      a[u] = k;
    } else {
      int b, c;
      scanf("%d%d", &b, &c);
      --b, --c;
      if(c <= b) {
        printf("%lld\n", rightTree.answer(c, b));
      } else {
        printf("%lld\n", leftTree.answer(c, b));
      }
    }
  }
  return 0;
}
