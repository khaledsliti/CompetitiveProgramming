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
string to_string(const string& s) { return '"' + s + '"'; }

string to_string(const char* s) { return to_string((string)s); }

string to_string(bool b) { return (b ? "true" : "false"); }

template <typename A, typename B>
string to_string(const pair<A, B>& p);

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);

template <typename T>
string to_string(const vector<T>& v) {
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (i > 0) res += ", ";
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
  for (const auto& x : v) {
    if (!first) res += ", ";
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}

template <typename A, typename B>
string to_string(const pair<A, B>& p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " +
         to_string(get<2>(p)) + ")";
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
int arr[N];
int idx[N];
int ans;

void update(int i, int j) {
  if (arr[i] > arr[j]) {
    swap(i, j);
  }

  if (arr[i] > 0) {
    ans -= idx[arr[i] - 1] > idx[arr[i]];
  }
  if (arr[i] < n - 1) {
    ans -= idx[arr[i]] > idx[arr[i] + 1];
  }
  if (arr[j] > 0 && arr[j] - 1 > arr[i]) {
    ans -= idx[arr[j] - 1] > idx[arr[j]];
  }
  if (arr[j] < n - 1) {
    ans -= idx[arr[j]] > idx[arr[j] + 1];
  }

  swap(idx[arr[i]], idx[arr[j]]);
  if (arr[i] > 0) {
    ans += idx[arr[i] - 1] > idx[arr[i]];
  }
  if (arr[i] < n - 1) {
    ans += idx[arr[i]] > idx[arr[i] + 1];
  }
  if (arr[j] > 0 && arr[j] - 1 > arr[i]) {
    ans += idx[arr[j] - 1] > idx[arr[j]];
  }
  if (arr[j] < n - 1) {
    ans += idx[arr[j]] > idx[arr[j] + 1];
  }
  swap(arr[i], arr[j]);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  int m;
  cin >> m;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    --arr[i];
    idx[arr[i]] = i;
  }

  ans = 1;
  for (int i = 0; i + 1 < n; i++) {
    if (idx[i] > idx[i + 1]) {
      ans++;
    }
  }

  while (m--) {
    int i, j;
    cin >> i >> j;
    --i, --j;
    update(i, j);
    cout << ans << endl;
  }

  return 0;
}
