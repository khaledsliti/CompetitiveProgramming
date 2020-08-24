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

const int N = 1e5 + 5;
const int L = 18;

int n;
int a[N], lg[N];
int sp_min[N][L], sp_max[N][L];

void precompute() {
  for(int i = 0; i < n; i++) {
    sp_min[i][0] = a[i];
    sp_max[i][0] = a[i];
  }
  for(int j = 1; (1 << j) <= n; j++) {
    for(int i = 0; i + (1 << j) <= n; i++) {
      sp_min[i][j] = min(sp_min[i][j - 1], sp_min[i + (1 << (j - 1))][j - 1]);
      sp_max[i][j] = max(sp_max[i][j - 1], sp_max[i + (1 << (j - 1))][j - 1]);
    }
  }
}

int getMax(int l, int r) {
  int lo = lg[r - l + 1];
  return max(sp_max[l][lo], sp_max[r - (1 << lo) + 1][lo]);
}

int getMin(int l, int r) {
  int lo = lg[r - l + 1];
  return min(sp_min[l][lo], sp_min[r - (1 << lo) + 1][lo]);
}

void calc(int i, int nxt_l, int left_part, int nxt_r, int right_part, int innerLen, ll& ans1, ll& ans2) {
  // debug(i, nxt_l, nxt_r, left_part, right_part);
  // calc right
  if(nxt_r - i + 1 <= right_part) {
    int st = nxt_r - i + 1;
    int en = min(innerLen, right_part);
    ans1 += en - st + 1;
  }

  // calc left
  if(i - nxt_l + 1 <= left_part) {
    int st = i - nxt_l + 1;
    int en = min(innerLen, left_part);
    ans1 += en - st + 1;
  }

  // calc middle
  left_part = min(left_part, innerLen - 1);
  if(left_part > 0 && left_part + right_part >= innerLen) {
    int en = left_part + right_part - innerLen;
    en = min(en, left_part - 1);
    ans2 += en + 1;
  }
}

void solve() {
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  long long ans1 = 0, ans2 = 0;

  precompute();

  for(int i = 0; i < n; i++) {
    // calc as Max
    {
      int lo = i, hi = n - 1, nxt_r = i;
      while(lo <= hi) {
        int mid = (lo + hi) >> 1;
        if(getMax(i, mid) == a[i]) {
          nxt_r = mid;
          lo = mid + 1;
        } else {
          hi = mid - 1;
        }
      }
      lo = 0, hi = i;
      int nxt_l = i;
      while(lo <= hi) {
        int mid = (lo + hi) >> 1;
        if(getMax(mid, i) == a[i]) {
          nxt_l = mid;
          hi = mid - 1;
        } else {
          lo = mid + 1;
        }
      }
      // here I have nxt_l and nxt_r
      int innerLen = nxt_r - nxt_l + 1;
      int left_part = 0, right_part = 0;
      // calc right_part
      if(nxt_r < n - 1) {
        int lo = nxt_r + 1, hi = n - 1;
        while(lo <= hi) {
          int mid = (lo + hi) >> 1;
          if(getMin(nxt_r + 1, mid) > a[i]) {
            right_part = mid - nxt_r;
            lo = mid + 1;
          } else {
            hi = mid - 1;
          }
        }
      }
      // calc left_part
      if(nxt_l > 0) {
        int lo = 0, hi = nxt_l - 1;
        while(lo <= hi) {
          int mid = (lo + hi) >> 1;
          if(getMin(mid, nxt_l - 1) > a[i]) {
            left_part = nxt_l - mid;
            hi = mid - 1;
          } else {
            lo = mid + 1;
          }
        }
      }
      // calc now
      calc(i, nxt_l, left_part, nxt_r, right_part, innerLen, ans1, ans2);
    }

    // calc as Min
    {
      int lo = i, hi = n - 1, nxt_r = i;
      while(lo <= hi) {
        int mid = (lo + hi) >> 1;
        if(getMin(i, mid) == a[i]) {
          nxt_r = mid;
          lo = mid + 1;
        } else {
          hi = mid - 1;
        }
      }
      lo = 0, hi = i;
      int nxt_l = i;
      while(lo <= hi) {
        int mid = (lo + hi) >> 1;
        if(getMin(mid, i) == a[i]) {
          nxt_l = mid;
          hi = mid - 1;
        } else {
          lo = mid + 1;
        }
      }
      // here I have nxt_l and nxt_r
      int innerLen = nxt_r - nxt_l + 1;
      int left_part = 0, right_part = 0;
      // calc right_part
      if(nxt_r < n - 1) {
        int lo = nxt_r + 1, hi = n - 1;
        while(lo <= hi) {
          int mid = (lo + hi) >> 1;
          if(getMax(nxt_r + 1, mid) < a[i]) {
            right_part = mid - nxt_r;
            lo = mid + 1;
          } else {
            hi = mid - 1;
          }
        }
      }
      // calc left_part
      if(nxt_l > 0) {
        int lo = 0, hi = nxt_l - 1;
        while(lo <= hi) {
          int mid = (lo + hi) >> 1;
          if(getMax(mid, nxt_l - 1) < a[i]) {
            left_part = nxt_l - mid;
            hi = mid - 1;
          } else {
            lo = mid + 1;
          }
        }
      }
      // calc now
      calc(i, nxt_l, left_part, nxt_r, right_part, innerLen, ans1, ans2);
    }
  }

  long long ans = ans1 / 2 + ans2;

  printf("%lld\n", ans);
}

int main()
{
  lg[1] = 0;
  for(int i = 2; i < N; i++)
    lg[i] = 1 + lg[i >> 1];
  int T;
  scanf("%d", &T);
  while(T--)
    solve();
  return 0;
}
