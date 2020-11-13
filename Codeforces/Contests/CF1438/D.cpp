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

const int N = 1e5 + 5;

int n;
int a[N];

void solve(vector<int>& idx) {
  vector<array<int, 3>> sol;
  for(int i = 0; i + 2 < sz(idx); i += 2) {
    sol.pb({idx[i], idx[i + 1], idx[i + 2]});
  }
  for(int i = sz(idx) - 5; i >= 0; i -= 2) {
    sol.pb({idx[i], idx[i + 1], idx.back()});
  }
  cout << "YES" << endl;
  assert(sz(sol) <= n);
  cout << sz(sol) << endl;
  for(int i = 0; i < sz(sol); i++) {
    for(int j = 0; j < 3; j++)
      cout << sol[i][j] + 1 << " ";
    cout << endl;
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }

  if(n & 1) {
    vector<int> idx;
    for(int i = 0; i < n; i++) {
      idx.pb(i);
    }
    solve(idx);
  } else {
    int s = 0;
    for(int i = 0; i < n; i++) {
      s ^= a[i];
    }
    for(int i = 0; i < n; i++) {
      int cur = s ^ a[i];
      if(cur == a[i]) {
        vector<int> idx;
        for(int j = 0; j < n; j++) {
          if(i != j) {
            idx.pb(j);
          }
        }
        solve(idx);
        return 0;
      }
    }
    cout << "NO" << endl;
  }
  return 0;
}
