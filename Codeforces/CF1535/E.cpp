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

const int N = 3e5 + 5;
const int L = 19;

int n = 1;
int cap[N], cost[N];
int par[N][L];
unordered_map<int, int> nodeIdx;

int goUp(int cur, int steps) {
  for(int j = L - 1; j >= 0; j--) {
    if((1 << j) <= steps) {
      steps -= (1 << j);
      cur = par[cur][j];
    }
  }
  return cur;
}

void solve(int node, int need) {
  int inital = need;
  int curNode = node;
  int steps = 0;
  for(int j = L - 1; j >= 0; j--) {
    int anc = par[curNode][j];
    if(anc != -1 && cap[anc]) {
      curNode = anc;
      steps ^= (1 << j);
    }
  }
  long long ans = 0;
  while(need > 0) {
    int take = min(cap[curNode], need);
    need -= take;
    cap[curNode] -= take;
    ans += 1LL * take * cost[curNode];
    if(curNode == node || cap[curNode] > 0) {
      break;
    }
    curNode = goUp(node, steps--);
  }
  cout << inital - need << " " << ans << endl;
  cout.flush();
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);


  int q;
  cin >> q >> cap[0] >> cost[0];
  nodeIdx[0] = 0;
  for(int j = 0; j < L; j++) {
    par[0][j] = -1;
  }

  for(int i = 1; i <= q; i++) {
    int t;
    cin >> t;
    if(t == 1) {
      int p, a, c;
      cin >> p >> a >> c;
      p = nodeIdx[p];
      cap[n] = a;
      cost[n] = c;
      par[n][0] = p;
      for(int j = 1; j < L; j++) {
        par[n][j] = par[n][j - 1] != -1 ? par[par[n][j - 1]][j - 1] : -1;
      }
      nodeIdx[i] = n++;
    } else {
      int node, need;
      cin >> node >> need;
      node = nodeIdx[node];
      if(cap[node] == 0) {
        cout << "0 0" << endl;
        cout.flush();
      } else {
        solve(node, need);
      }
    }
  }

  return 0;
}
