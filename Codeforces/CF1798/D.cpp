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

const int N = 300005;

int n;
int arr[N];

void check(vector<int>& sol) {
  int min_ = INT_MAX, max_ = INT_MIN;
  for (int i = 0; i < n; i++) {
    min_ = min(min_, sol[i]);
    max_ = max(max_, sol[i]);
  }
  int diff = max_ - min_;
  for (int i = 0; i < n; i++) {
    int s = 0;
    for (int j = i; j < n; j++) {
      s += sol[j];
      if (abs(s) >= diff) {
        cout << i << " " << j << " " << abs(s) << " " << diff << endl;
        assert(false);
      }
    }
  }
}

void Solve() {
  cin >> n;
  int z = 0;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    z += arr[i] == 0;
  }
  if (z == n) {
    cout << "No" << endl;
    return;
  }
  int min_ = INT_MAX, max_ = INT_MIN;
  vector<int> pos, neg;
  for (int i = 0; i < n; i++) {
    min_ = min(min_, arr[i]);
    max_ = max(max_, arr[i]);
    if (arr[i] > 0) {
      pos.push_back(arr[i]);
    } else if (arr[i] < 0) {
      neg.push_back(arr[i]);
    }
  }
  int diff = max_ - min_;
  long long pos_s = 0, neg_s = 0;
  sort(rall(pos));
  sort(rall(neg));
  // debug(diff, pos, neg);
  vector<int> sol(n);
  for (int i = 0; i < n; i++) {
    debug(pos, neg, sol);
    if (sz(pos) && pos_s + pos.back() < diff) {
      sol[i] = pos.back();
      pos.pop_back();
      pos_s += sol[i];
      neg_s = 0;
      continue;
    }
    if (sz(neg) && neg_s - neg.back() < diff) {
      sol[i] = neg.back();
      neg.pop_back();
      neg_s -= sol[i];
      pos_s = 0;
      continue;
    }
  }

  for (int i = 0; i < z; i++) {
    sol[n - 1 - i] = 0;
  }
  cout << "Yes" << endl;
  for (int i = 0; i < n; i++) {
    cout << sol[i] << " ";
  }
  cout << endl;
  check(sol);
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int T;
  cin >> T;
  while(T--) {
    Solve();
  }
  return 0;
}
