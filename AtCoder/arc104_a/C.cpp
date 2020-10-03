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

const int N = 207;

int n;
int arr[N], A[N], B[N];
int cnt[N], pos[N];
int dp[N];

bool check(int l, int r) {
  int len = r - l + 1;
  for(int i = l; i < l + len / 2; i++) {
    int j = i + len / 2;
    // cerr << i << " " << j << " " << arr[i] << " " << arr[j] << " " << B[arr[j]] << endl;
    if(arr[i] == arr[j]) continue;
    if(arr[i] != -1 && arr[j] != -1 && arr[i] != arr[j]) return false;
    if(arr[i] != -1 && A[arr[i]] != i) return false;
    if(arr[j] != -1 && B[arr[j]] != j) return false;
  }
  return true;
}

int solve(int i) {
  if(i >= 2 * n) return 1;
  int& ret = dp[i];
  if(ret != -1) return ret;
  for(int j = i + 1; j < 2 * n; j += 2) {
    if(check(i, j) && solve(j + 1))
      return ret = 1;
  }
  return ret = 0;
}

int main()
{
  cin >> n;
  memset(arr, -1, sizeof arr);
  for(int i = 0; i < n; i++) {
    A[i] = B[i] = -1;
    for(int it = 0; it < 2; it++) {
      int a;
      cin >> a;
      if(a != -1) {
        --a;
        if(arr[a] != -1) {
          cout << "No" << endl;
          return 0;
        }
        if(it == 0) A[i] = a;
        else B[i] = a;
        arr[a] = i;
        cnt[i]++;
        pos[i] += a;
      }
    }
  }

  // for(int i = 0; i < 2 * n; i++) {
  //   cout << arr[i] << " ";
  // }
  // cout << endl;

  // for(int i = 0; i < n; i++) {
  //   debug(A[i], B[i]);
  // }

  // cout << check(0, 3) << endl;
  // return 0;

  memset(dp, -1, sizeof dp);
  cout << (solve(0) ? "Yes" : "No") << endl;
  return 0;
}
