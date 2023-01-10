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
const int Mod = 998244353;

int n, m;
int arr[N];
vector<int> divs;
int isp[N];

int calc(vector<int>& pr, int limit) {
  int n = sz(pr);
  long long ans = 0;
  for (int msk = 1; msk < (1 << n); msk++) {
    int cnt = 0;
    int v = 1;
    for (int i = 0; i < n; i++) {
      if (msk & (1 << i)) {
        v *= pr[i];
        cnt++;
      }
    }
    if(cnt & 1) {
      ans += limit / v;
    } else {
      ans -= limit / v;
    }
  }
  return limit - ans;
}

void solve() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  for (int i = 1; i < n; i++) {
    if (arr[i - 1] % arr[i] != 0) {
      cout << 0 << endl;
      return;
    }
  }

  divs.clear();
  for (int i = 1; i * i <= arr[0]; i++) {
    if (arr[0] % i == 0) {
      divs.push_back(i);
      if (arr[0] / i != i) {
        divs.push_back(arr[0] / i);
      }
    }
  }
  sort(rall(divs));

  // debug(divs);

  int a = 0;
  long long ans = 1;
  for (int i = 1; i < n; i++) {
    int b = a;
    while (divs[b] != arr[i]) {
      b++;
    }

    // debug(i, a, b, divs[b]);

    vector<int> pr;
    int last = a;
    for (int j = a + 1; j <= b; j++) {
      if (divs[last] % divs[j] == 0 && divs[j] % divs[b] == 0) {
        pr.push_back(divs[last] / divs[j]);
        last = j;
      }
    }
    sort(all(pr));
    pr.resize(unique(all(pr)) - begin(pr));
    // debug(pr);

    ans = (1LL * ans * calc(pr, m / arr[i])) % Mod;

    a = b;
  }
  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int T;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
