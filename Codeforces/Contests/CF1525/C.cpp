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

const int N = 3e5 + 5;

struct Robot {
  int pos, dir, idx;
};

int m;
int pos[N], ans[N];
vector<Robot> a, b;

void calc(vector<Robot>& a, int i, int j) {
  // debug(i, j);
  int idx1 = a[i].idx, idx2 = a[j].idx;
  int mid = abs(a[i].pos - a[j].pos) >> 1;
  if(a[i].dir == 0 && a[j].dir == 0) { // L L
    ans[idx1] = ans[idx2] = mid + a[i].pos;
  } else if(a[i].dir == 0 && a[j].dir == 1) { // L R
    int mn = min(m - a[j].pos, a[i].pos);
    // debug(a[i].pos, a[j].pos);
    a[i].pos -= mn;
    a[j].pos += mn;
    // debug(a[i].pos, a[j].pos);
    mid = abs(a[i].pos - a[j].pos) >> 1;
    int mx = max(m - a[j].pos, a[i].pos);
    // debug(mid + mx);
    ans[idx1] = ans[idx2] = mid + mx + mn;
  } else if(a[i].dir == 1 && a[j].dir == 0) { // R L
    ans[idx1] = mid;
    ans[idx2] = mid;
  } else if(a[i].dir == 1 && a[j].dir == 1) { // R R
    ans[idx1] = ans[idx2] = mid + m - a[j].pos;
  }
}

void solve(vector<Robot>& a) {
  sort(all(a), [](Robot& a, Robot& b) { return a.pos < b.pos; });
  // for(int i = 0; i < sz(a); i++) {
  //   debug(a[i].idx, a[i].pos, a[i].dir);
  // }
  vector<int> st;
  for(int i = 0; i < sz(a); i++) {
    if(a[i].dir == 1 || st.empty()) {
      st.push_back(i);
    } else {
      int idx = st.back();
      st.pop_back();
      calc(a, idx, i);
    }
  }
  while(st.size() >= 2) {
    int i = st.back(); st.pop_back();
    int j = st.back(); st.pop_back();
    calc(a, j, i);
  }
}

void solve() {
  int n;
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    cin >> pos[i];
    ans[i] = -1;
  }
  a.clear(); b.clear();
  for(int i = 0; i < n; i++) {
    char d;
    cin >> d;
    if(pos[i] & 1) {
      a.push_back({pos[i], d == 'R', i});
    } else {
      b.push_back({pos[i], d == 'R', i});
    }
  }
  solve(a);
  solve(b);
  for(int i = 0; i < n; i++)
    cout << ans[i] << " ";
  cout << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int T; cin >> T;
  while(T--) solve();
  return 0;
}
