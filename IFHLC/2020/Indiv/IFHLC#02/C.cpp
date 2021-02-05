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

const int N = 18, K = 101;
const int Inf = 1e9;

int n, c, k;
int s[N], cost[N];
vector<int> order;
int can[1 << N];
int dp[K][1 << N];
vector<int> bits[1 << N];
int lg[1 << N];

int main()
{
  #ifndef LOCAL
  freopen("cache.in", "r", stdin);
  freopen("cache.out", "w", stdout);
  #endif

  for(int i = 0; i < N; i++)
    lg[1 << i] = i;

  cin >> n >> c >> k;
  for(int i = 0; i < n; i++) {
    cin >> s[i];
  }
  for(int i = 0; i < n; i++) {
    cin >> cost[i];
  }
  order.resize(k);
  for(int i = 0; i < k; i++) {
    cin >> order[i];
    order[i]--;
  }
  for(int msk = 0; msk < (1 << n); ++msk) {
    ll sum = 0;
    for(int i = 0; i < n; i++) {
      if(msk & (1 << i)) {
        sum += s[i];
      }
    }
    can[msk] = sum <= c;
  }

  dp[0][0] = 0;
  for(int i = 1; i < (1 << n); i++) {
    dp[0][i] = Inf;
  }

  for(int i = 1; i <= k; i++) {
    int idx = order[i - 1];
    for(int msk = 0; msk < (1 << n); msk++) {
      if(!(msk & (1 << idx)) || !can[msk]) {
        dp[i][msk] = Inf;
      } else {
        dp[i][msk] = min(dp[i - 1][msk], cost[idx] + dp[i - 1][msk ^ (1 << idx)]);
        int nw = ((1 << n) - 1) ^ msk;
        for(int sub = nw; sub > 0; sub -= sub & -sub) {
          int j = lg[sub & -sub];
          dp[i][msk] = min(dp[i][msk], dp[i - 1][msk ^ (1 << j)]);
          dp[i][msk] = min(dp[i][msk], cost[idx] + dp[i - 1][msk ^ (1 << j) ^ (1 << idx)]);
        }
      }
    }
  }
  
  int best = 0;
  for(int i = 0; i < (1 << n); i++) {
    if(dp[k][best] > dp[k][i]) {
      best = i;
    }
  }

  cout << dp[k][best] << endl;
  
  vector<int> sol;
  for(int i = k - 1; i > 0; i--) {
    int idx = order[i];
    if(dp[i][best] == dp[i + 1][best]) {
      sol.push_back(-1);
      continue;
    } else if(dp[i][best ^ (1 << idx)] + cost[idx] == dp[i + 1][best]) {
      sol.push_back(-1);
      best ^= (1 << idx);
      continue;
    }
    int nw = ((1 << n) - 1) ^ best;
    for(int sub = nw; sub > 0; sub -= sub & -sub) {
      int j = lg[sub & -sub];
      if(dp[i + 1][best] == dp[i][best | (1 << j)]) {
        sol.push_back(j + 1);
        best |= (1 << j);
        break;
      } else if(dp[i + 1][best] == cost[idx] + dp[i][best ^ (1 << j) ^ (1 << idx)]) {
        sol.push_back(j + 1);
        best ^= (1 << j) | (1 << idx);
        break;
      }
    }
  }
  
  cout << 0 << endl;
  reverse(all(sol));
  for(int i = 0; i < sz(sol); i++) {
    if(sol[i] == -1) cout << 0 << endl;
    else cout << 1 << " " << sol[i] << endl;
  }
  return 0;
}
