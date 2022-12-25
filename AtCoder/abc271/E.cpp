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

const int N = 2e5 + 5;
const long long Inf = 1e18;

int n, m, e, k;
int ord[N];
vector<int> idx[N];
int head[N], nxt[N], to[N], cost[N], fr[N];
long long dist[N];

void init() {
  e = 0;
  memset(head, -1, sizeof head);
}

void addEdge(int f, int t, int c) {
  nxt[e] = head[f];
  head[f] = e;
  fr[e] = f;
  to[e] = t;
  cost[e++] = c;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m >> k;
  init();
  for(int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    addEdge(--a, --b, c);
  }
  for(int i = 0; i < k; i++) {
    cin >> ord[i];
    ord[i]--;
    idx[ord[i]].push_back(i);
  }
  priority_queue<pair<long long, int>> pq;
  for(int i = 0; i < k; i++) {
    dist[i] = Inf;
  }
  for(int i = 0; i < k; i++) {
    if(fr[ord[i]] == 0) {
      dist[i] = cost[ord[i]];
      pq.push({-dist[i], i});
    }
  }
  long long ans = -1;
  while(!pq.empty()) {
    int cur_idx = pq.top().second;
    ll cc = -pq.top().first;
    pq.pop();
    int src = to[ord[cur_idx]];
    if(src == n - 1) {
      ans = cc;
      break;
    }
    for(int k = head[src]; ~k; k = nxt[k]) {
      int nxt_idx = lower_bound(all(idx[k]), cur_idx) - begin(idx[k]);
      if(nxt_idx >= sz(idx[k])) continue;
      nxt_idx = idx[k][nxt_idx];
      if(dist[nxt_idx] > dist[cur_idx] + cost[k]) {
        dist[nxt_idx] = dist[cur_idx] + cost[k];
        pq.push({-dist[nxt_idx], nxt_idx});
      }
    }
  }
  cout << ans << endl;
  return 0;
}
