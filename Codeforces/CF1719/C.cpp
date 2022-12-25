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

const int N = 2e5 + 5;

struct Query {
  int idx, player, games;
  bool operator<(const Query& rhs) const {
    return games < rhs.games;
  }
};

int n;
deque<int> dq;
int curr_ans[N], arr[N];
int q_ans[N];
vector<Query> qr;


void solve() {
  int q;
  cin >> n >> q;
  dq.clear();
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
    dq.push_back(i);
  }
  qr.clear();
  for(int i = 0; i < q; i++) {
    int x, t;
    cin >> x >> t;
    qr.push_back({i, --x, t});
  }
  sort(all(qr));
  for(int i = 0; i < n; i++) {
    curr_ans[i] = 0;
  }
  int qr_idx = 0;
  for(int it = 1; it <= n; it++) {
    int first = dq.front(); dq.pop_front();
    int second = dq.front(); dq.pop_front();
    if(arr[first] < arr[second]) {
      swap(first, second);
    }
    curr_ans[first]++;
    dq.push_front(first);
    dq.push_back(second);
    while(qr_idx < sz(qr) && qr[qr_idx].games == it) {
      int curr_q = qr[qr_idx].idx;
      q_ans[curr_q] = curr_ans[qr[qr_idx].player];
      qr_idx++;
    }
  }
  int first = dq.front();
  while(qr_idx < sz(qr)) {
    int add = 0;
    if (qr[qr_idx].player == first) {
      add = qr[qr_idx].games - n;
    }
    q_ans[qr[qr_idx].idx] = curr_ans[qr[qr_idx].player] + add;
    qr_idx++;
  }
  for(int i = 0; i < q; i++) {
    cout << q_ans[i] << endl;
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int T;
  cin >> T;
  while(T--) {
    solve();
  }
  return 0;
}
