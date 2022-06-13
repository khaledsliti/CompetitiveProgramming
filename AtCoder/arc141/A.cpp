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

// copy first period
string get(const string& a, const int per) {
  string r = a;
  for(int i = 0; i < per; i++) {
    for(int j = i + per; j < sz(a); j += per) {
      r[j] = r[i];
    }
  }
  return r;
}

void maxi(long long n, long long& ans, string tmp) {
  long long t = stoll(tmp);
  if(t <= n) {
    ans = max(ans, t);
  }
}

void solve() {
  long long n;
  cin >> n;
  long long ans = 11;
  string s = to_string(n);
  for(int per = 1; per < sz(s); per++) {
    if(sz(s) % per == 0) {
      string p = s;
      string tmp = get(p, per);
      maxi(n, ans, tmp);
      // debug(p, per, tmp);
      for(int i = per - 1; i >= 0; i--) {
        if(p[i] > '0') {
          p[i]--;
          maxi(n, ans, get(p, per));
        }
        p[i] = '9';
      }
    }
  }
  if(sz(s) > 2) {
    ans = max(ans, stoll(string(sz(s) - 1, '9')));
  }
  cout << ans << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int T; cin >> T;
  while(T--) {
    solve();
  }
  return 0;
}
