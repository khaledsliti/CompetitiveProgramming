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
const int A = 256;
const int Lg = 20;

int n;
char s[N];
int suff[N], t_suff[N], rnk[N], rnk_start[N], t_rnk[N];
int lcp[N];
int* head = t_rnk, *nxt = lcp;

int sparse[N][Lg], lg[N];
int R[N], L[N];

struct Comparator {
  int len;
  Comparator(int len): len(len) {}
  bool operator()(const int& i, const int& j) const {
    return rnk[i] < rnk[j] || (rnk[i] == rnk[j] && rnk[i + len] < rnk[j + len]);
  }
};

void build_suff_array() {
  int len;
  memset(head, -1, A * sizeof(head));
  for(len = 0; !len || s[len - 1]; len++) {
    nxt[len] = head[s[len]];
    head[s[len]] = len;
  }
  int cur_rnk = 0, j = 0;
  for(int i = 0; i < A; i++) {
    if(head[i] != -1) {
      rnk_start[cur_rnk] = j;
      for(int k = head[i]; ~k; k = nxt[k]) {
        suff[j++] = k;
        rnk[k] = cur_rnk;
      }
      cur_rnk++;
    }
  }
  t_suff[0] = suff[0];
  t_rnk[0] = 0;
  for(int width = 1; t_rnk[len - 1] != len - 1; width <<= 1) {
    Comparator isSmaller(width);
    for(int i = 0; i < len; i++) {
      j = suff[i] - width;
      if(j < 0) continue;
      t_suff[rnk_start[rnk[j]]++] = j;
    }
    for(int i = 1; i < len; i++) {
      bool nw_rnk =  isSmaller(t_suff[i - 1], t_suff[i]);
      t_rnk[i] = t_rnk[i - 1] + nw_rnk;
      if(nw_rnk) rnk_start[t_rnk[i]] = i;
    }
    for(int i = 0; i < len; i++) {
      suff[i] = t_suff[i];
      rnk[suff[i]] = t_rnk[i];
    }
  }
}

void build_lcp() {
  for(int i = 0, len = 0; s[i]; i++) {
    int j = suff[rnk[i] - 1];
    while(s[i + len] == s[j + len]) len++;
    lcp[rnk[i]] = len;
    if(len) len--;
  }
}

void build_sparse() {
  for(int i = 0; i <= n; i++) {
    sparse[i][0] = lcp[i];
  }
  for(int j = 1; (1 << j) <= n + 1; j++) {
    for(int i = 0; i + (1 << j) <= n + 1; i++) {
      sparse[i][j] = min(sparse[i][j - 1], sparse[i + (1 << (j - 1))][j - 1]);
    }
  }
}

int getMin(int l, int r) {
  int i = lg[r - l + 1];
  return min(sparse[l][i], sparse[r - (1 << i) + 1][i]);
}

bool are_equal(int i, int j, int len) {
  i = rnk[i], j = rnk[j];
  if(i > j) swap(i, j);
  return getMin(i + 1, j) >= len;
}

bool isPalin(int i, int j) {
  int half = j - i + 1 >> 1;
  return are_equal(i, n - 1 - j, half);
}

void solve() {
  scanf("%s", s);
  n = strlen(s);
  for(int i = 0; i < n; i++) {
    s[i + n] = s[n - 1 - i];
  }
  s[2 * n] = 0;
  n <<= 1;
  build_suff_array();
  build_lcp();
  lcp[0] = 0;
  build_sparse();
  for(int i = 0; i < n; i++) {
    R[i] = L[i] = 0;
  }
  for(int i = 0; i < n / 2; i++) {
    int lo = 0, hi = min(i, n / 2 - i - 1), len = 0;
    while(lo <= hi) {
      int cur_len = (lo + hi) / 2;
      if(isPalin(i - cur_len, i + cur_len)) {
        len = cur_len;
        lo = cur_len + 1;
      } else {
        hi = cur_len - 1;
      }
    }
    if(i > 0) {
      if(i - len == 0) {
        R[i - len + 1] = max(R[i - len + 1], 2 * len - 1);
      } else {
        R[i - len] = max(R[i - len], 2 * len + 1);
      }
    }
    if(i < n / 2  - 1) {
      if(i + len == n / 2 - 1) {
        L[i + len - 1] = max(L[i + len - 1], 2 * len - 1);
      } else {
        L[i + len] = max(L[i + len], 2 * len + 1);
      }
    }
  }

  for(int i = 0; i < n / 2 - 1; i++) {
    if(s[i] != s[i + 1]) continue;
    int lo = 0, hi = min(i, n / 2 - 2 - i), len = 0;
    while(lo <= hi) {
      int cur_len = (lo + hi) / 2;
      if(isPalin(i - cur_len, i + 1 + cur_len)) {
        len = cur_len;
        lo = cur_len + 1;
      } else {
        hi = cur_len - 1;
      }
    }
    if(i - len == 0) {
      R[i - len + 1] = max(R[i - len + 1], 2 * len);
    } else {
      R[i - len] = max(R[i - len], 2 * len + 2);
    }
    if(i + len + 1 == n / 2 - 1) {
      L[i + len] = max(L[i + len], 2 * len);
    } else {
      L[i + len + 1] = max(L[i + len + 1], 2 * len + 2);
    }
  }
  // cout << s << endl;
  // for(int i = 0; i < n / 2; i++) {
  //   cout << L[i];
  // }
  // cout << endl;
  // for(int i = 0; i < n / 2; i++) {
  //   cout << R[i];
  // }
  // cout << endl;

  for(int i = 1; i < n / 2; i++) {
    L[i] = max(L[i], L[i - 1]);
  }
  for(int i = n / 2 - 2; i >= 0; i--) {
    R[i] = max(R[i], R[i + 1]);
  }

  int ans = 0;
  for(int i = 0; i < n / 2 - 1; i++) {
    ans = max(ans, L[i] + R[i + 1]);
  }
  printf("%d\n", ans);
}

int main()
{
  lg[1] = 0;
  for(int i = 2; i < N; i++) {
    lg[i] = 1 + lg[i >> 1];
  }

  int T;
  scanf("%d", &T);
  while(T--) {
    solve();
  }
  return 0;
}
