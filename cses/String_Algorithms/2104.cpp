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

const int A = 26;
const int N = 5e5 + 1;

template <typename T>
class SparseTable {
  int n, depth;
  vector<T> values;
  vector<vector<int>> dp;
  function<bool(T, T)> cmp;

  int LargestBit(int x) {
    int cnt = 0;
    while (x) cnt++, x >>= 1;
    return cnt - 1;
  }

  int Best(int a, int b) const { return cmp(values[a], values[b]) ? a : b; }

  void Build() {
    n = (int)values.size();
    depth = LargestBit(n) + 1;
    dp.clear();
    dp.resize(n);
    for (int i = 0; i < n; i++) {
      dp[i].resize(depth);
      dp[i][0] = i;
    }
    for (int len = 1; (1 << len) <= n; len++) {
      for (int i = 0; i + (1 << (len - 1)) < n; i++) {
        dp[i][len] = Best(dp[i][len - 1], dp[i + (1 << (len - 1))][len - 1]);
      }
    }
  }

 public:
  SparseTable(function<bool(T, T)> cmp) : cmp(cmp) {}

  void Init(T* first, T* last) {
    values.clear();
    for (T* i = first; i != last; i++) {
      values.push_back(*i);
    }
    Build();
  }

  int QueryIndex(int l, int r) {
    int dep = LargestBit(r - l + 1);
    return Best(dp[l][dep], dp[r - (1 << dep) + 1][dep]);
  }

  T QueryValue(int l, int r) { return values[QueryIndex(l, r)]; }
};

int n;
char s[N];
int suff[N], rnk[N], t_rnk[N];
SparseTable<int> spt([](int a, int b) { return a <= b; });

struct Comparator {
  int len;
  Comparator(int len) : len(len) {}
  bool operator()(const int& i, const int& j) const {
    return rnk[i] < rnk[j] || (rnk[i] == rnk[j] && rnk[i + len] < rnk[j + len]);
  }
};

void BuildSuffArray() {
  int len;
  for (len = 0; !len || s[len - 1]; len++) {
    rnk[len] = s[len];
    suff[len] = len;
  }
  t_rnk[0] = 0;
  for (int width = 1; t_rnk[len - 1] != len - 1; width <<= 1) {
    Comparator isSmaller(width);
    sort(suff, suff + len, isSmaller);
    for (int i = 1; i < len; i++) {
      t_rnk[i] = t_rnk[i - 1] + isSmaller(suff[i - 1], suff[i]);
    }
    for (int i = 0; i < len; i++) {
      rnk[suff[i]] = t_rnk[i];
    }
  }
}

int First(const string& t) {
  int start = 1, end = n, level = 0;
  for (char c : t) {
    int low = start, high = end, newStart = -1;
    while (low <= high) {
      int mid = low + high >> 1;
      if (s[suff[mid] + level] >= c) {
        newStart = mid;
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }
    if (newStart == -1 || s[suff[newStart] + level] != c) {
      return -2;
    }
    low = newStart, high = end;
    int newEnd = newStart;
    while (low <= high) {
      int mid = low + high >> 1;
      if (s[suff[mid] + level] == c) {
        newEnd = mid;
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }

    start = newStart;
    end = newEnd;
    level++;
  }

  return spt.QueryValue(start, end);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> s;
  n = strlen(s);
  BuildSuffArray();
  spt.Init(suff, suff + n + 1);

  int k;
  cin >> k;
  for (int i = 0; i < k; i++) {
    string t;
    cin >> t;
    cout << First(t) + 1 << endl;
  }

  return 0;
}
