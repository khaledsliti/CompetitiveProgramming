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

const int N = 1e3 + 5, E = 2e3 + 5;

int n, e;
int head[N], nxt[E], to[E], fr[E];
vector<int> edges;

void init() {
  e = 0;
  memset(head, -1, sizeof head);
}

void addEdge(int f, int t) {
  nxt[e] = head[f];
  head[f] = e;
  fr[e] = f;
  to[e] = t;
  e++;
}

void addBiEdge(int a, int b) {
  addEdge(a, b);
  addEdge(b, a);
}

void dfs(int u, int p) {
  for(int k = head[u]; ~k; k = nxt[k]) {
    int v = to[k];
    if(v != p) {
      edges.push_back(k);
      dfs(v, u);
      edges.push_back(k);
    }
  }
}

int getGCD(int l, int r) {
  vector<int> nodes;
  for(int i = l; i <= r; i++) {
    nodes.push_back(fr[edges[i]]);
    nodes.push_back(to[edges[i]]);
  }
  sort(all(nodes));
  nodes.resize(unique(all(nodes)) - begin(nodes));
  cout << "? " << sz(nodes);
  for(int u: nodes) {
    cout << " " << u + 1;
  }
  cout << endl;
  int g; cin >> g;
  return g;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  init();
  for(int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    addBiEdge(--a, --b);
  }
  int mx;
  cout << "? " << n;
  for(int i = 0; i < n; i++) {
    cout << " " << i + 1;
  }
  cout << endl;
  cin >> mx;
  dfs(0, -1);

  // debug("edges");
  // for(int e: edges) {
  //   cout << fr[e] + 1 << " " << to[e] + 1 << endl;
  // }

  int s = 0, e = 2 * (n - 1);
  while(s < e) {
    // debug(s, e);
    int mid = (s + e) >> 1;
    if(getGCD(s, mid) == mx) {
      e = mid;
    } else {
      s = mid + 1;
    }
  }
  cout << "! " << fr[edges[s]] + 1 << " " << to[edges[s]] + 1 << endl;
  return 0;
}
