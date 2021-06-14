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

const int N = 501;
const int INF = 1e9;

int n, k;
int dist[N][N];
pair<int, int> fr[N][N];
vector<vector<int>> sol;
vector<pair<int, int>> path;
vector<int> va, vb;

void bfs() {
  for(int i = 0; i <= n; i++) {
    for(int j = 0; j <= n; j++) {
      dist[i][j] = -1;
    }
  }
  dist[n][0] = 0;
  queue<pair<int, int>> q;
  q.push({n, 0});
  while(!q.empty()) {
    int a = q.front().first;
    int b = q.front().second;
    q.pop();
    assert(a + b == n);
    if(a == 0) break;
    for(int take = 0; take <= min(a, k); take++) {
      int other = k - take;
      if(other > b) continue;
      int new_a = a - take + other;
      int new_b = b - other + take;
      if(dist[new_a][new_b] == -1) {
        dist[new_a][new_b] = 1 + dist[a][b];
        fr[new_a][new_b] = {take, other};
        q.push({new_a, new_b});
      }
    }
  }
}

void getPath(int a, int b) {
  if(a == n) return;
  int take = fr[a][b].first;
  int other = fr[a][b].second;
  path.push_back({take, other});
  int prv_a = a + take - other;
  int prv_b = b - take + other;
  getPath(prv_a, prv_b);
}

void solve() {
  int cur_a = n, cur_b = 0;
  for(int i = 0; i < n; i++) {
    va.push_back(i);
  }
  for(int i = 0; i < sz(path); i++) {
    int take = path[i].first;
    int other = path[i].second;
    vector<int> tmp;
    sol.push_back(vector<int>());
    while(take-- > 0) {
      sol.back().push_back(va.back());
      tmp.push_back(va.back());
      va.pop_back();
    }
    while(other-- > 0) {
      sol.back().push_back(vb.back());
      va.push_back(vb.back());
      vb.pop_back();
    }
    while(sz(tmp) > 0) {
      vb.push_back(tmp.back());
      tmp.pop_back();
    }
    assert(sol.back().size() == k);
  }
}

int main()
{
  cin >> n >> k;
  bfs();

  if(dist[0][n] == -1) {
    cout << -1 << endl;
    cout.flush();

    return 0;
  }

  getPath(0, n);

  reverse(all(path));
  solve();

  int ans = 0;
  for(int i = 0; i < sz(sol); i++) {
    cout << "?";
    for(int j : sol[i])
      cout << " " << j + 1;
    cout << endl;
    cout.flush();

    int r;
    cin >> r;
    ans ^= r;
  }

  cout << "! " << ans << endl;
  cout.flush();
  return 0;
}
