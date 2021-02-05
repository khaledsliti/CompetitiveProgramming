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

const int N = 4e5 + 5;
const int L = 20;

int n;
long long k;
long long arr[N], pref[N];
int nxt[N][L];

ll get(int l, int r) {
  return pref[r] - (l > 0 ? pref[l - 1] : 0);
}

int main()
{
  cin >> n >> k;
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
    arr[i + n] = arr[i];
  }
  for(int i = 0; i < 2 * n; i++) {
    pref[i] = arr[i];
    if(i > 0) pref[i] += pref[i - 1];
  }
  nxt[2 * n][0] = 2 * n;
  for(int i = 0; i < 2 * n; i++) {
    int l = i, r = 2 * n - 1, idx = i;
    while(l <= r) {
      int mid = (l + r) / 2;
      if(get(i, mid) <= k) {
        idx = mid;
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    nxt[i][0] = idx + 1;
  }

  int s = 2 * n + 1;
  for(int j = 1; j < L; j++) {
    for(int i = 0; i < s; i++) {
      nxt[i][j] = nxt[nxt[i][j - 1]][j - 1];
    }
  }

  int best = n;
  for(int i = 0; i < n; i++) {
    int last = i + n;
    int cur = i;
    int steps = 0;
    for(int j = L - 1; j >= 0; j--) {
      if(nxt[cur][j] < last) {
        cur = nxt[cur][j];
        steps |= (1 << j);
      }
    }
    best = min(best, 1 + steps);
  }
  cout << best << endl;
  return 0;
}
