// RedStone
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
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

const int N = 3e5 + 6;

int n;
int arr[N];
int s, t;
int smf[N];
set<int> pos[N];


int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  for (int i = 2; i < N; i++) {
    smf[i] = i;
  }
  for (int i = 2; i < N; i++) {
    if (smf[i] == i) {
      for (int j = i + i; j < N; j += i) {
        smf[j] = min(smf[j], i);
      }
    }
  }

  auto fact = [&](int a) -> vector<int> {
    vector<int> r;
    for (int p = smf[a]; a > 1; p = smf[a]) {
      r.push_back(p);
      while(smf[a] == p) {
        a /= p;
      }
    }
    return r;
  };

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  cin >> s >> t;
  --t, --s;

  if (t == s) {
    cout << 1 << endl;
    cout << s + 1 << endl;
    return 0;
  }

  for (int i = 0; i < n; i++) {
    for (int p : fact(arr[i])) {
      pos[p].insert(i);
    }
  }

  queue<int> q;
  q.push(s);
  vector<int> fr(n, -1);

  for (int p : fact(arr[s])) {
    pos[p].erase(s);
  }
  
  while(!q.empty()) {
    int u = q.front();
    q.pop();
    vector<int> nxt;
    for (int p : fact(arr[u])) {
      for (int v : pos[p]) {
        nxt.push_back(v);
      }
    }
    sort(all(nxt));
    nxt.resize(unique(all(nxt)) - begin(nxt));

    for (int v : nxt) {
      q.push(v);
      fr[v] = u;
      for (int p : fact(arr[v])) {
        pos[p].erase(v);
      }
    }
  }

  if (fr[t] == -1) {
    cout << -1 << endl;
    return 0;
  }

  vector<int> path;
  while(t != -1) {
    path.push_back(t);
    t = fr[t];
  }

  reverse(all(path));
  cout << sz(path) << endl;
  for (int x : path) {
    cout << x + 1 << " ";
  }
  cout << endl;

  return 0;
}
