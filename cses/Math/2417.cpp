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

const int N = 1e6 + 4;

int n, arr[N];
int smf[N];
int cnt[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  for (int i = 0; i < N; i++) {
    smf[i] = i;
  }
  for (int i = 2; i < N; i++) {
    if (smf[i] == i) {
      for (int j = 2 * i; j < N; j += i) {
        smf[j] = min(smf[j], i);
      }
    }
  }

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sort(arr, arr + n);

  long long ans = 1LL * n * (n - 1) / 2;
  for (int i = 0; i < n; i++) {
    vector<int> pr;
    for (int p = smf[arr[i]]; p > 1; p = smf[arr[i]]) {
      pr.push_back(p);
      while (arr[i] % p == 0) {
        arr[i] /= p;
      }
    }

    for (int mask = 1; mask < (1 << sz(pr)); mask++) {
      int prod = 1, s = 0;
      for (int i = 0; i < sz(pr); i++) {
        if (mask & (1 << i)) {
          prod *= pr[i];
          s++;
        }
      }
      if(s & 1) {
        ans -= cnt[prod];
      } else {
        ans += cnt[prod];
      }
      cnt[prod]++;
    }
  }

  cout << ans << endl;
  return 0;
}
