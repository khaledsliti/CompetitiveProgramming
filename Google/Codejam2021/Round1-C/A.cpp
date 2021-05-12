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

int solve(int a, int b, vector<int>& arr, int k) {
  int n = sz(arr);
  // debug(arr);
  int idx1 = lower_bound(all(arr), a) - begin(arr);
  int idx2 = lower_bound(all(arr), b) - begin(arr);
  if(idx1 == idx2) {
    if(idx1 == 0) {
      int m = max(a, b);
      return m + (arr[0] - m - 1) / 2;
    } else if(idx1 >= n) {
      int m = min(a, b);
      return k - m + 1 + (m - arr[n - 1] - 1) / 2;
    } else {
      int m1 = min(a, b), m2 = max(a, b);
      return m2 - m1 + 1 + (arr[idx1] - m2 - 1) / 2 + (m1 - arr[idx1 - 1] - 1) / 2;
    }
  } else {
    int ans = 0;
    if(idx1 == 0) {
      ans += a + (arr[0] - a - 1) / 2;
    } else if(idx1 >= n) {
      ans += k - a + 1 + (a - arr[n - 1] - 1) / 2;
    } else {
      ans += 1 + (arr[idx1] - a - 1) / 2 + (a - arr[idx1 - 1] - 1) / 2;
    }
    if(idx2 == 0) {
      ans += b + (arr[0] - b - 1) / 2;
    } else if(idx2 >= n) {
      ans += k - b + 1 + (b - arr[n - 1] - 1) / 2;
    } else {
      ans += 1 + (arr[idx2] - b - 1) / 2 + (b - arr[idx2 - 1] - 1) / 2;
    }
    return ans;
  }
}

void solve() {
  int n, k;
  scanf("%d%d", &n, &k);
  vector<int> arr(n);
  for(int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  sort(all(arr));

  // cout << solve(4, 8, arr, k) << endl;
  // return;

  vector<int> pts;
  if(arr[0] > 1) {
    pts.push_back(arr[0] - 1);
  }
  for(int i = 0; i + 1 < sz(arr); i++) {
    int a = arr[i], b = arr[i + 1];
    if(a + 1 < b) {
      pts.push_back(a + 1);
      pts.push_back(b - 1);
      pts.push_back((a + b) / 2);
    }
  }
  if(arr[sz(arr) - 1] < k) {
    pts.push_back(arr[sz(arr) - 1] + 1);
  }
  int ans = 0;
  for(int i = 0; i < sz(pts); i++) {
    for(int j = i; j < sz(pts); j++) {
      ans = max(ans, solve(pts[i], pts[j], arr, k));
    }
  }
  printf("%.10f\n", ans * 1.0 / k);
}

int main()
{
  int T, tc = 1;
  scanf("%d", &T);
  while(T--) {
    printf("Case #%d: ", tc++);
    solve();
  }
  return 0;
}
