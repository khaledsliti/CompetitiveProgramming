// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
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

const int N = 51;

int main()
{
  int T;
  cin >> T;
  while(T--) {
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    int cnt[m];
    int sol[n][m];
    memset(cnt, 0, sizeof(cnt));
    memset(sol, 0, sizeof(sol));
    vector<int> cols(m);
    iota(all(cols), 0);
    bool yes = true;
    for(int i = 0; i < n; i++) {
      sort(all(cols), [&cnt](int a, int b) {
        return cnt[a] < cnt[b];
      });
      // debug(cols);
      if(cnt[cols[a - 1]] >= b) {
        yes = false;
        break;
      }
      for(int j = 0; j < a; j++)
        sol[i][cols[j]] = 1, cnt[cols[j]]++;
    }
    for(int i = 0; i < m; i++)
      if(cnt[i] != b)
        yes = false;
    if(yes) {
      cout << "YES" << endl;
      for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
          cout << sol[i][j];
        cout << endl;
      }
    }else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
