#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int)(x).size())

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
const int Mod = 1e9 + 7;

int n;
vector<int> dv[N];
map<pair<int, int>, long long> pairs; // sum, gcd

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  for(int i = 1; i < N; i++) {
    for(int j = 1; j * j <= i; j++) {
      if(i % j == 0) {
        dv[i].push_back(j);
        if(i / j != j) {
          dv[i].push_back(i / j);
        }
      }
    }
  }
  
  cin >> n;
  
  for(int sum = 2; sum <= n - 1; sum++) {
    for(int g : dv[sum]) {
      int q = sum / g;
      assert(sum % g == 0);
      if(q < 2) continue;
      pairs[{sum, g}] += q - 1;
      debug(sum, g, q);
    }
  }
  debug(pairs);

  long long ans = 0;
  for(auto p: pairs) {
    int sum = p.first.first;
    int g = p.first.second;
    long long cnt = p.second % Mod;
    int c = n - sum;
    long long v = 1LL * c / __gcd(c, g) * g;
    ans = (ans + v % Mod * cnt % Mod) % Mod;
    debug(sum, g, c, cnt, v);
  }
  cout << ans << endl;

  return 0;
}
