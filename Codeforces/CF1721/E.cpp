// RedStone
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
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

const int N = 1e6 + 5;

string s;
int f[N];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> s;
  f[0] = 0;
  for(int i = 1, k = 0; i < sz(s); i++) {
    while(k > 0 && s[i] != s[k])
      k = f[k - 1];
    if(s[i] == s[k])
      k++;
    f[i] = k;
  }

  unordered_map<string, int> cnt;
  for(int st = f[sz(s) - 1]; st > 0; st = f[st - 1]) {
    string tmp = "";
    for(int j = st; j < sz(s) && j - st + 1 <= 10; j++) {
      tmp += s[j];
      cnt[tmp] = max(cnt[tmp], j + 1);
    }
  }


  int q; cin >> q;
  while(q--) {
    string t; cin >> t;
    vector<int> ans(sz(t), 0);
    
    for(int i = 0; i < sz(t); i++) {
      for(int j = i; j < sz(t); j++) {
        if(j - i >= sz(s) || s[j - i] != t[j]) {
          break;
        }
        ans[j] = max(ans[j], j - i + 1);
      }
    }

    string tmp = "";
    for(int i = 0; i < sz(t); i++) {
      tmp += t[i];
      int cur = sz(s) - 1;
      ans[i] = max(ans[i], cnt[tmp]);
    }
  
    for(int i = 0; i < sz(t); i++) {
      cout << ans[i] << " ";
    }
    cout << endl;
  }
  return 0;
}
