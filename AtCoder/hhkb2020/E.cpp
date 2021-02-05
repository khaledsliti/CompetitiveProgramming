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

const int N = 2002;
const int Mod = 1e9 + 7;

int n, m;
string s[N];
int cnt[N][N];

ll mpow(ll a, ll b) {
  ll r = 1;
  while(b > 0) {
    if(b & 1) r = (r * a) % Mod;
    a = a * a % Mod;
    b >>= 1;
  }
  return r;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m;
  int tot = 0;
  for(int i = 0; i < n; i++) {
    cin >> s[i];
    for(int j = 0; j < m; j++) {
      tot += s[i][j] == '.';
    }
  }
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(s[i][j] == '.') {
        int l = j;
        while(l < m && s[i][l] == '.') l++;
        for(int k = j; k < l; k++) {
          cnt[i][k] += l - j;
        }
        j = l - 1;
      }
    }
  }
  for(int j = 0; j < m; j++) {
    for(int i = 0; i < n; i++) {
      if(s[i][j] == '.') {
        int l = i;
        while(l < n && s[l][j] == '.') l++;
        for(int k = i; k < l; k++) {
          cnt[k][j] += l - i;
        }
        i = l - 1;
      }
    }
  }

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(s[i][j] == '.') {
        cnt[i][j]--;
      }
    }
  }

  int ans = 0;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(s[i][j] == '#') continue;
      int rem = tot - cnt[i][j];
      ans += mpow(2, rem) * (mpow(2, cnt[i][j]) - 1) % Mod;
      ans %= Mod;
    }
  }
  cout << ans << endl;
  return 0;
}
