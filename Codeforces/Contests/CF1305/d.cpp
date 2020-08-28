// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

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

const int N = 1001;

int n;
vector<int> g[N];
int done[N], fr[N];

void ans(int u) {
  cout << "! " << u << endl;
  cout.flush();
}

int query(int a, int b) {
  cout << "? " << a << " " << b << endl;
  cout.flush();
  int r;
  cin >> r;
  return r;
}

void dfs(int u, int p) {
  done[u] = true;
  for(int v : g[u]) {
    if(v != p && !done[v]) {
      dfs(v, u);
    }
  }
}

vector<int> get_path() {
  vector<int> leaf;
  for(int i = 1 ; i <= n ; i++) {
    if(!done[i]) {
      int cnt = 0;
      for(int v : g[i])
        cnt += !done[v];
      if(cnt <= 1) {
        leaf.push_back(i);
      }
    }
  }
  for(int i = 1 ; i <= n ; i++)
    fr[i] = -1;
  fr[leaf.front()] = 0;
  queue<int> q;
  q.push(leaf.front());
  while(!q.empty()) {
    int u = q.front();
    q.pop();
    for(int v : g[u]) {
      if(fr[v] == -1) {
        fr[v] = u;
        q.push(v);
      }
    }
  }
  vector<int> path;
  int cur = leaf.back();
  do {
    path.pb(cur);
    cur = fr[cur];
  } while(cur > 0);
  return path;
}

int main()
{
  cin >> n;
  for(int i = 1 ; i < n ; i ++) {
    int a, b;
    cin >> a >> b;
    g[a].pb(b);
    g[b].pb(a);
  }
  while(true) {
    vector<int> path = get_path();
    if(sz(path) == 1) {
      ans(path[0]);
      break;
    }
    int lca = query(path.front(), path.back());
    if(lca == path.front() || lca == path.back()) {
      ans(lca);
      break;
    }
    for(int i = 0 ; i < sz(path) ; i++)
      if(path[i] == lca)
        dfs(path[i - 1], lca), dfs(path[i + 1], lca);
  }
  return 0;
}
