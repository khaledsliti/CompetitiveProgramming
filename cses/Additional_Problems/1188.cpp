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

const int N = 2e5 + 5;

multiset<int> lens;
set<pair<int, int>> vals;

void get(int idx, int& l, int& r) {
  auto it = vals.lower_bound({idx + 1, idx});
  --it;
  l = it->first, r = it->second;
}

void add(int l, int r) {
  vals.insert({l, r});
  lens.insert(r - l + 1);
}

void del(int l, int r) {
  vals.erase({l, r});
  lens.erase(lens.find(r - l + 1));
}

void merge(int i, int j) {
  int a, b, c, d;
  get(i, a, b);
  get(j, c, d);
  del(a, b);
  del(c, d);
  add(min(a, c), max(b, d));
}

int getMax() {
  return *lens.rbegin();
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  string s;
  cin >> s;

  for(int i = 0; i < sz(s); i++) {
    int j = i;
    while(j < sz(s) && s[i] == s[j]) j++;
    add(i, j - 1);
    i = j - 1;
  }

  int q;
  cin >> q;
  while(q--) {
    int idx;
    cin >> idx; --idx;
    int l, r;
    get(idx, l, r);
    del(l, r);
    add(idx, idx);
    if(idx > 0 && idx == l) {
      merge(idx - 1, idx);
    } else {
      add(l, idx - 1);
    }
    if(idx < sz(s) - 1 && idx == r) {
      merge(idx, idx + 1);
    } else {
      add(idx + 1, r);
    }
    cout << getMax() << " ";
  }
  cout << endl;
  return 0;
}
