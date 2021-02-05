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
#define EPS 1e-12

const int N = 205;

struct Graph {
  int n, src;
  vector<int> dst;
  vector<int> par;
  Graph(int _n): n(_n) {
    par.resize(n);
    for(int i = 0; i < n; i++) {
      par[i] = i;
    }
  }
  int fs(int x) {
    return x == par[x] ? x : par[x] = fs(par[x]);
  }
  void unit(int x, int y) {
    x = fs(x), y = fs(y);
    if(x != y) 
      par[x] = y;
  }
  bool check() {
    for(auto x: dst) {
      if(fs(src) == fs(x)) {
        return true;
      }
    }
    return false;
  }
};

int db_cmp (long double a, long double b) {
  if (fabs(a - b) < EPS)
    return 0;
  return (a > b) * 2 - 1;
}

int n, m, r, total_nodes;
pair<int, int> car;
vector<pair<int, int>> lane[N];
vector<pair<double, double>> nodes[N];
vector<int> idx[N];

bool check(double delta) {
  Graph g(total_nodes);
  g.src = -1;
  for(int i = 0; i < sz(nodes[0]); i++) {
    if(db_cmp(nodes[0][i].first + delta, car.first) <= 0 && db_cmp(nodes[0][i].second - delta, car.second) >= 0) {
      g.src = idx[0][i];
      break;
    }
  }
  if(g.src == -1) return false;
  for(int i = 0; i < sz(nodes[n - 1]); i++) {
    g.dst.push_back(idx[n - 1][i]);
  }
  for(int i = 0; i < n - 1; i++) {
    for(int j = 0; j < sz(nodes[i]); j++) {
      for(int k = 0; k < sz(nodes[i + 1]); k++) {
        double a = nodes[i][j].first + delta;
        double b = nodes[i][j].second - delta;
        double c = nodes[i + 1][k].first + delta;
        double d = nodes[i + 1][k].second - delta;
        a = max(a, c);
        b = min(b, d);
        if(db_cmp(b - a, car.second - car.first) >= 0) {
          g.unit(idx[i][j], idx[i + 1][k]);
        }
      }
    }
  }
  return g.check();
}

int main()
{
  cin >> n >> m >> r;

  cin >> car.first >> car.second >> car.first;
  car.second += car.first;

  for(int i = 0; i < m - 1; i++) {
    int l, len, st;
    cin >> l >> len >> st;
    lane[l].push_back({st, st + len});
  }

  total_nodes = 0;
  for(int i = 0; i < n; i++) {
    if(lane[i].empty()) {
      nodes[i].push_back({0, r});
    } else {
      nodes[i].push_back({0, lane[i].front().first});
      for(int j = 1; j < sz(lane[i]); j++) {
        double a = lane[i][j - 1].second;
        double b = lane[i][j].first;
        nodes[i].push_back({a, b});
      }
      nodes[i].push_back({lane[i].back().second, r});
    }
    for(int j = 0; j < sz(nodes[i]); j++) {
      idx[i].push_back(total_nodes++);
    }
  }

  double lo = 0.0, hi = r, best = -1;

  for(int it = 0; it < 100; it++) {
    double mid = (lo + hi) / 2.0;
    if(check(mid)) {
      best = mid;
      lo = mid;
    } else {
      hi = mid;
    }
  }

  if(best == -1) cout << "Impossible" << endl;
  else cout << fixed << setprecision(10) << best << endl;

  return 0;
}
