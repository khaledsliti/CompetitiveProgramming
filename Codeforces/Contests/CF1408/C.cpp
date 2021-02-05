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

const int N = 1e5 + 5;

int n, l;
int a[N];

bool check(double t) {
  double pos1 = 0, s = 1;
  double tmp = t;
  for(int i = 1; i <= n + 1; i++) {
    double nxt = a[i];
    double dist = nxt - pos1;
    double need = dist / s;
    if(need <= tmp) {
      tmp -= need;
      pos1 = nxt;
      s++;
    } else {
      pos1 += tmp * s;
      break;
    }
  }

  double pos2 = l;
  s = 1;
  tmp = t;
  for(int i = n; i >= 0; i--) {
    double nxt = a[i];
    double dist = pos2 - nxt;
    double need = dist / s;
    if(need <= tmp) {
      tmp -= need;
      pos2 = nxt;
      s++;
    } else {
      pos2 -= tmp * s;
      break;
    }
  }

  return pos1 >= pos2;
}

void solve() {
  cin >> n >> l;
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  a[0] = 0;
  a[n + 1] = l;

  double lo = 0, hi = l;

  for(int it = 0; it < 100; it++) {
    double mid = (hi + lo) / 2.0;
    if(check(mid)) {
      hi = mid;
    } else {
      lo = mid;
    }
  }

  cout << fixed << setprecision(10) << lo << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int T;
  cin >> T;
  while(T--) {
    solve();
  }
  return 0;
}
