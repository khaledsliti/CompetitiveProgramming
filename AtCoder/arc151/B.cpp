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

const int Mod = 998244353;
const int N = 2e5 + 5;

template<int N>
struct DSU {
  int n;
  int par[N], size[N];
  int comp;
  void init(int _n) {
    n = _n;
    for(int i = 0; i < n; i++) {
      par[i] = i;
      size[i] = 1;
    }
    comp = n;
  }
  int find(int x) {
    return x == par[x] ? x : par[x] = find(par[x]);
  }
  int getSize(int x) {
    return size[find(x)];
  }
  bool unite(int x, int y) {
    x = find(x);
    y = find(y);
    if(x != y) {
      par[x] = y;
      size[y] += size[x];
      comp--;
      return true;
    }
    return false;
  }
};

long long mpow(long long a, long long b) {
  if(!b) return 1LL;
  long long r = mpow(a, b >> 1);
  r = (r * r) % Mod;
  if(b&1) {
    r = (r * a) % Mod;
  }
  return r;
}

int n, m;
int p[N];
DSU<N> ds;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    cin >> p[i];
    --p[i];
  }
  ds.init(n);
  long long ans = 0;
  for(int i = 0; i < n; i++) {
    if(ds.find(i) == ds.find(p[i])) {
      continue;
    }
    assert(ds.comp >= 2);
    int rem = ds.comp - 2;
    int cur = (1LL * m * (m - 1) / 2 % Mod * mpow(m, ds.comp - 2) % Mod) % Mod;
    ans = (ans + cur) % Mod;
    ds.unite(i, p[i]);
  }
  cout << ans << endl;
  return 0;
}
