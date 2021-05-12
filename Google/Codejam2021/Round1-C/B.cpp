// Guess Who's Back
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

const ll INF = 1e18 + 5;

ll tn[19];
vector<int> all_them;

int len(ll a) {
  return to_string(a).size();
}

ll get(ll cur, int width) {
  ll res = 0;
  while(len(res) < width) {
    res = res * tn[len(cur)] + cur;
    cur++;
  }
  return res;
}

bool check(ll cur, ll n) {
  ll res = 0;
  int width = sz(to_string(n));
  while(res == 0 || len(res) < width) {
    if(res != 0 && len(res) + len(cur) > width) {
      return false;
    }
    res = res * tn[len(cur)] + cur;
    cur++;
  }
  return res > n;
}

void get_smallest(ll& best, int width, ll n) {
  for(int i = 1; i < 10; i++) {
    ll tmp = get(i, width);
    if(tmp > n) {
      best = min(best, tmp);
    }
  }
  int l = 1;
  for(int i = 2; i < width; i++) {
    if(width % i == 0) {
      l = width / i;
      break;
    }
  }
  for(int i = 1; i <= 9; i++) {
    ll tmp = get(i * tn[l - 1], width);
    if(tmp > n) {
      best = min(best, tmp);
    }
  }
}

void solve() {
  ll n;
  scanf("%lld", &n);
  string s = to_string(n);
  ll cur = 0;
  ll best = INF;
  for(int i = 0; i < sz(s) - 1; i++) {
    cur = cur * 10 + s[i] - '0';
    if(check(cur, n)) {
      best = min(best, get(cur, sz(s)));
    }
    if(check(cur + 1, n)) {
      best = min(best, get(cur + 1, sz(s)));
    }
  }
  get_smallest(best, sz(s), n);
  get_smallest(best, sz(s) + 1, n);
  
  // ll idx = upper_bound(all(all_them), n) - begin(all_them);
  // cout << all_them[idx] << " ";

  printf("%lld\n", best);
}

bool check(int i) {
  string s = to_string(i);
  ll cur = 0;
  for(int j = 0; j < sz(s) - 1; j++) {
    cur = cur * 10 + s[j] - '0';
    if(get(cur, sz(s)) == i)
      return true;
  }
  return false;
}

void gen() {
  for(int i = 12; i <= 2e6; i++) {
    if(check(i)) {
      all_them.push_back(i);
    }
  }
}

int main()
{
  tn[0] = 1;
  for(int i = 1; i <= 18; i++) {
    tn[i] = tn[i - 1] * 10;
  }
  // gen();

  int T;
  scanf("%d", &T);
  for(int tc = 1; tc <= T; tc++) {
    printf("Case #%d: ", tc);
    solve();
  }
  return 0;
}
