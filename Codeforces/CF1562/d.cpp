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

const int N = 3e5 + 5;

int get(char c) {
  return c == '+' ? 1 : -1;
}

int solve(int l, int r, vector<int>& a, map<int, vector<int>>& pos) {
  int need = (a[r] - (l > 0 ? a[l - 1] : 0) - 1) / 2;
  int pref = (l > 0 ? a[l - 1] : 0) + need;
  debug(a);
  debug(pref, need);
  debug(pos[pref]);
  int idx = lower_bound(all(pos[pref]), l) - begin(pos[pref]);
  if(idx >= sz(pos[pref]) || pos[pref][idx] > r) {
    return l;
  }
  return pos[pref][idx] + 2;
}

void solve() {
  int n, q;
  string s;
  cin >> n >> q >> s;
  vector<int> a(n + 5);
  for(int i = 0; i < n; i++) {
    a[i] = get(s[i]);
  }
  for(int i = 1; i < n; i += 2) {
    a[i] *= -1;
  }
  for(int i = 1; i < n; i++) {
    a[i] += a[i - 1];
  }
  // for(int i = 0; i < n; i++)
  //   cout << a[i] << " ";
  // cout << endl;
  map<int, vector<int>> pos;
  pos[0].push_back(-1);
  for(int i = 0; i < n; i++) {
    pos[a[i]].push_back(i);
  }
  // debug(a);
  while(q--) {
    int l, r;
    cin >> l >> r;
    --l, --r;
    vector<int> sol;
    if((r - l + 1) % 2 == 0) {
      sol.push_back(l++ + 1);
    }

    sol.push_back(solve(l, r, a, pos) + 1);

    cout << sz(sol) << endl;
    for(int x: sol) {
      cout << x << " ";
    }
    cout << endl;
  }
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
