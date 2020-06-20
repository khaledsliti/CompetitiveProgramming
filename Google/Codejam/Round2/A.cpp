// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
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

ll L, R;

inline ll f(ll st, ll en) {
  return (st + en) * (en - st + 1) / 2;
}

ll get_max(ll rem, ll st) {
  ll l = st, r = 2e9, index = st;
  while(l <= r) {
    ll mid = (l + r) / 2;
    ll cur = f(st, mid);
    if(cur <= rem) {
      index = mid;
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  return index;
}

ll get(ll& rem, ll x, ll st) {
  if(rem < st) return 0;
  ll l = st, r = 2e9, index = st;
  while(l <= r) {
    ll mid = (l + r) / 2;
    ll cur = f(st, mid);
    if(cur >= rem - x) {
      index = mid;
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  if(f(st, index) <= rem) {
    rem -= f(st, index);
    return index - st + 1;
  } else {
    index = get_max(rem, st);
    rem -= f(st, index);
    return index - st + 1;
  }
}

ll g(ll st, ll k) {
  return (st + k) * (k + 1);
}

ll solve(ll rem, ll st) {
  ll l = 0, r = 2e9, ans = 0;
  while(l <= r) {
    ll mid = (l + r) / 2;
    ll val = g(st, mid - 1);
    if(val <= rem) {
      ans = mid;
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  return ans;
}

void solve() {
  cin >> L >> R;
  ll sol = 0;
  while(true) {
    if(L >= R) {
      ll take = get(L, R, sol + 1);
      if(take <= 1 && sol) {
        sol += take;
        break;
      } else sol += take;
    } else {
      ll take = get(R, L, sol + 1);
      if(take <= 1 && sol) {
        sol += take;
        break;
      } else sol += take;
    }
  }
  if(sol + 1 <= L && L >= R) {
    ll tl = solve(L, sol + 1);
    ll tr = solve(R, sol + 2);
    L -= g(sol + 1, tl - 1);
    R -= g(sol + 2, tr - 1);
    sol += tl + tr;
  } else if(sol + 1 <= R && R > L) {
    ll tl = solve(L, sol + 2);
    ll tr = solve(R, sol + 1);
    L -= g(sol + 2, tl - 1);
    R -= g(sol + 1, tr - 1);
    sol += tl + tr;
  }
  cout << sol << " " << L << " " << R << endl;
}

int main()
{
  int T, tc = 1;
  cin >> T;
  while(T--) {
    cout << "Case #" << tc++ << ": ";
    solve();
  }
  return 0;
}
