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

const int N = 2e5 + 5;

int n;
vector<int> arr;
int pos[N], occ[N];
int dp[N];

void solve() {
  cin >> n;
  arr.clear(); arr.resize(n);
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
    occ[arr[i]]++;
  }
  sort(all(arr));
  arr.resize(unique(all(arr)) - begin(arr));
  for(int i = 0; i < sz(arr); i++) {
    pos[arr[i]] = i;
  }

  int ans = 0;
  for(int i = sz(arr) - 1; i >= 0; i--) {
    dp[i] = occ[arr[i]];
    for(int j = 2 * arr[i]; j < N; j += arr[i]) {
      if(pos[j] != -1)
        dp[i] = max(dp[i], occ[arr[i]] + dp[pos[j]]);
    }
    ans = max(ans, dp[i]);
  }

  cout << n - ans << endl;
  for(int i = 0; i < n; i++) {
    pos[arr[i]] = -1;
    occ[arr[i]] = 0;
  }
}

int main()
{
  memset(pos, -1, sizeof pos);
  int T;
  scanf("%d", &T);
  while(T--) {
    solve();
  }
  return 0;
}
