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
int d[N], nxt[N];

int find(int x) {
  return nxt[x] == x ? x : nxt[x] = find(nxt[x]);
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  priority_queue<pair<int, int>> pq;
  for(int i = 0; i < n; i++) {
    cin >> d[i];
    if(d[i])
      pq.push({d[i], i});
  }
  vector<pair<int, int>> sol;
  while(pq.empty() == false) {
    int u = pq.top().second;
    pq.pop();
    vector<int> nodes;
    while(d[u]-- > 0) {
      if(!sz(pq)) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
      }
      int v = pq.top().second;
      pq.pop();
      sol.push_back({u, v});
      --d[v];
      nodes.push_back(v);
    }
    for(int u : nodes) {
      if(d[u]) {
        pq.push({d[u], u});
      }
    }
  }
  cout << sz(sol) << endl;
  for(int i = 0; i < sz(sol); i++) {
    cout << sol[i].first + 1 << " " << sol[i].second + 1 << endl;
  }
  return 0;
}
