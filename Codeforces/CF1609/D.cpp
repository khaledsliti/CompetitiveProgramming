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

struct DSU {
  vector<int> par, size;
  void init(int n) {
    par.clear(); par.resize(n);
    size.clear(); size.resize(n);
    for(int i = 0; i < n; i++) {
      par[i] = i;
      size[i] = 1;
    }
  }
  int find(int x) {
    return x == par[x] ? x : par[x] = find(par[x]);
  }
  bool unite(int x, int y) {
    x = find(x), y = find(y);
    if(x != y) {
      par[x] = y;
      size[y] += size[x];
      return true;
    }
    return false;
  }
};

const int N = 1e3 + 5;

int n;
DSU dsu;
int x[N], y[N];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int d;
  cin >> n >> d;
  for(int i = 0; i < d; i++) {
    cin >> x[i] >> y[i];
    --x[i], --y[i];
  }
  for(int i = 0; i < d; i++) {
    int cnt = 1;
    dsu.init(n);
    for(int j = 0; j <= i; j++) {
      if(dsu.unite(x[j], y[j]) == false) {
        cnt++;
      }
    }
    vector<int> a;
    for(int j = 0; j < n; j++) {
      if(dsu.find(j) == j) {
        a.push_back(dsu.size[j]);
      }
    }
    sort(rall(a));
    int ans = 0;
    for(int j = 0; j < cnt; j++) {
      ans += a[j];
    }
    cout << ans - 1 << endl;
  }

  return 0;
}
