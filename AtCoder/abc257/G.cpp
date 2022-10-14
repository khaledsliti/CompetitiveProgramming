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



struct Hash {
  const ll MOD1 = 1000000009;
  const ll MODINVERSE1 = 554687505;
  
  const ll MOD2 = 1190494759;
  const ll MODINVERSE2 = 976577732;

  const ll BASE = 128;

  vector<ll> h1, h2;
  vector<ll> bp1, bp2;
  
  Hash(const string& s) {
    bp1.resize(sz(s) + 1);
    bp2.resize(sz(s) + 1);
    for(int i = 0; i <= sz(s); i++) {
      bp1[i] = i == 0 ? 1LL : bp1[i - 1] * BASE % MOD1;
      bp2[i] = i == 0 ? 1LL : bp2[i - 1] * BASE % MOD2;
    }

    h1.resize(sz(s));
    h2.resize(sz(s));

    ll so_far1 = 0, so_far2 = 0;
    for(int i = 0; i < sz(s); i++) {
      so_far1 = (so_far1 * BASE % MOD1 + s[i]) % MOD1;
      h1[i] = so_far1;
      so_far2 = (so_far2 * BASE % MOD2 + s[i]) % MOD2;
      h2[i] = so_far2;
    }
  }

  pair<ll, ll> get(int l, int r) {
    ll r1 = h1[r];
    ll r2 = h2[r];
    if(l > 0) {
      r1 -= h1[l - 1] * bp1[r - l + 1] % MOD1;
      r1 = (r1 % MOD1 + MOD1) % MOD1;

      r2 -= h2[l - 1] * bp2[r - l + 1] % MOD2;
      r2 = (r2 % MOD2 + MOD2) % MOD2;
    }
    return {r1, r2};
  }
};

const int N = 5e5 + 5;
const int INF = 1e9;

int seg[N << 2];

void update(int cur, int s, int e, int idx, int val) {
  if(s > idx || e < idx) return;
  if(s == e) {
    seg[cur] = val;
    return;
  }
  int mid = (s + e) / 2;
  update(2 * cur + 1, s, mid, idx, val);
  update(2 * cur + 2, mid + 1, e, idx, val);
  seg[cur] = min(seg[2 * cur + 1], seg[2 * cur + 2]);
}

int query(int cur, int s, int e, int i, int j) {
  if(s > j || e < i) return INF;
  if(s >= i && e <= j) return seg[cur];
  int mid = (s + e) / 2;
  return min(query(2 * cur + 1, s, mid, i, j), query(2 * cur + 2, mid + 1, e, i, j));
}


int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  string s, t;
  cin >> s >> t;
  Hash hs(s), ht(t);

  int ans;
  auto update = [&](int idx, int val) {
    // cout << "update " << idx << " " << val << endl;
    ans = val;
    ::update(0, 0, sz(t), idx, val);
  };
  auto query = [&](int l, int r) {
    // cout << "query " << l << " " << r << " " << ::query(0, 0, sz(t), l, r) << endl;
    return ::query(0, 0, sz(t), l, r);
  };

  update(sz(t), 0);

  for(int i = sz(t) - 1; i >= 0; i--) {
    int low = i, high = sz(t) - 1, j = -1;
    while(low <= high) {
      int mid = (low + high) >> 1;
      int len = mid - i + 1;
      if(len <= sz(s) && hs.get(0, len - 1) == ht.get(i, mid)) {
        j = mid;
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }
    if (j == -1) {
      update(i, INF);
      ans = INF;
      continue;
    }
    update(i, 1 + query(i + 1, j + 1));
  }

  if(ans >= INF) {
    ans = -1;
  }
  cout << ans << endl;
  return 0;
}
