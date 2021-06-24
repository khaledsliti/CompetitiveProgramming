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

const int N = 2e6 + 5;

ll L, R;
ll divis[N];
ll smf[N];

vector<ll> getFactors(ll n) {
  vector<ll> p;
  for(ll i = n; i > 1; ) {
    ll cur = smf[i];
    p.push_back(cur);
    while(i % cur == 0)
      i /= cur;
  }
  return p;
}

ll getNotCoprime(ll n) {
  ll ans = 0;
  vector<ll> fact = getFactors(n);
  for(ll mask = 1; mask < (1 << sz(fact)); mask++) {
    ll mult = 1;
    ll parity = 0;
    for(ll i = 0; i < sz(fact); i++) {
      if(mask & (1 << i)) {
        mult *= fact[i];
        parity++;
      }
    }
    ll val = R / mult - (L - 1) / mult;
    if(parity & 1) ans += val;
    else ans -= val;
  }
  return ans;
}

ll getCoprime(ll n) {
  return R - L + 1 - getNotCoprime(n);
}

int main()
{
  cin >> L >> R;
  L = max(L, 2LL);
  for(ll i = L; i <= R; i++) {
    for(ll j = 2 * i; j <= R; j += i) {
      divis[j]++;
    }
  }

  for(ll i = 0; i < N; i++) {
    smf[i] = i;
  }
  for(ll i = 2; i < N; i++) {
    if(smf[i] == i) {
      for(ll j = i; j < N; j += i) {
        smf[j] = min(1LL * smf[j], i);
      }
    }
  }

  ll ans = 1LL * (R - L + 1) * (R - L + 1);
  for(ll i = L; i <= R; i++) {
    ans -= 2LL * divis[i] + 1;
    ans -= getCoprime(i);
  }
  cout << ans << endl;
  return 0;
}
