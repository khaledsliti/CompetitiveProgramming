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

const int N = 2e5 + 5;
const int L = 18;

int n, q, cur_cycle;

vector<int> g[N];
int anc[N][L], lev[N], in[N];

int nxt[N], par[N], col[N];
int cycle_index[N], cycle_ord[N], cycle_length[N];
int tree_root[N];

void dfs_lca(int u, int p, int root) {
  tree_root[u] = root;
  anc[u][0] = p;
  for(int j = 1 ; (1 << j) < n ; j++)
    anc[u][j] = ~anc[u][j - 1] ? anc[anc[u][j - 1]][j - 1] : -1;
  for(int i = 0 ; i < (int)g[u].size() ; i++){
    int v = g[u][i];
    if(v != p){
      lev[v] = 1 + lev[u];
      dfs_lca(v, u, root);
    }
  }
}

int get_lca(int a, int b)
{
  if(lev[a] < lev[b])
    swap(a,b);
  int lg = 0;
  for(; (1 << lg) <= lev[a] ; lg++);
  lg--;
  for(int i = lg ; i >= 0 ; i--)
    if(lev[a] - (1 << i) >= lev[b])
      a = anc[a][i];
  if(a == b) return a;
  for(int i = lg ; i >= 0 ; i--)
    if(anc[a][i] != anc[b][i])
      a = anc[a][i], b = anc[b][i];
  return anc[a][0];
}

int getPath(int a, int b) {
  assert(cycle_index[a] != -1 && cycle_index[a] == cycle_index[b]);
  int result = cycle_ord[b] - cycle_ord[a];
  if(result < 0) result += cycle_length[cycle_index[a]];
  return result;
}

int solve(int a, int b) {
  if(cycle_index[a] != -1) {
    if(cycle_index[b] == cycle_index[a])
      return getPath(a, b);
  } else {
    int root = tree_root[a];
    if(cycle_index[b] == -1) {
      if(tree_root[b] == root && get_lca(a, b) == b)
        return lev[a] - lev[b];
    } else if(cycle_index[b] == cycle_index[root]) {
      return lev[a] + getPath(root, b);
    }
  }
  return -1;
}

int main()
{
  cin >> n >> q;
  for(int i = 0; i < n; i++) {
    cin >> nxt[i];
    --nxt[i];
  }

  cur_cycle = 0;
  for(int i = 0; i < n; i++) {
    col[i] = 0;
    cycle_index[i] = -1;
  }

  for(int i = 0; i < n; i++) {
    if(col[i] == 0) {
      for(int cur = i; col[cur] != 2; cur = nxt[cur]) {
        if(col[cur] == 1) {
          vector<int> cycle {cur};
          for(int k = nxt[cur]; k != cur; k = nxt[k]) {
            cycle.push_back(k);
          }
          cycle_length[cur_cycle] = sz(cycle);
          for(int i = 0; i < sz(cycle); i++) {
            cycle_index[cycle[i]] = cur_cycle;
            cycle_ord[cycle[i]] = i;
          }
          cur_cycle++;
          break;
        } else {
          col[cur] = 1;
        }
      }
      for(int cur = i; col[cur] != 2; cur = nxt[cur])
        col[cur] = 2;
    }
  }

  for(int i = 0; i < n; i++) {
    int j = nxt[i];
    if(cycle_index[i] == -1 || cycle_index[j] == -1) {
      in[i]++; 
      g[j].push_back(i);
    }
  }
  for(int i = 0; i < n; i++)
    if(!in[i]) {
      lev[i] = 0;
      dfs_lca(i, -1, i);
    }

  while(q--) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    cout << solve(a, b) << endl;
  }
  return 0;
}
