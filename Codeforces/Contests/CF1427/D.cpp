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

const int N = 55;

int n;
vector<int> a;
int pos[N];
vector<vector<int>> sol;

bool isSorted() {
  bool yes = true;
  for(int i = 1; i < n; i++) {
    yes &= a[i] >= a[i - 1];
  }
  return yes;
}

void go(vector<int>& len) {
  vector<vector<int>> tmp;
  int idx = 0;
  for(int i = 0; i < sz(len); i++) {
    tmp.push_back(vector<int>());
    for(int j = 0; j < len[i]; j++) {
      tmp.back().push_back(a[idx++]);
    }
  }
  reverse(all(tmp));
  a.clear();
  for(int i = 0; i < sz(tmp); i++) {
    for(int x: tmp[i]) {
      a.push_back(x);
    }
  }
}

int main()
{
  cin >> n;
  a.resize(n);
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    --a[i];
  }
  // debug(a);
  while(isSorted() == false) {
    for(int i = 0; i < n; i++) {
      pos[a[i]] = i;
    }
    int target;
    for(int i = 0; i < n - 1; i++) {
      if(pos[i] > pos[i + 1]) {
        target = i;
        break;
      }
    }
    int x = pos[target], y = pos[target + 1];
    int z = y;
    while(a[z] + 1 == a[z + 1]) z++;
    // debug(x, y);
    vector<int> s;
    if(y > 0) {
      s.push_back(y);
    }
    s.push_back(z - y + 1);
    if(x > z) {
      s.push_back(x - z);
    }
    if(x < n - 1) {
      s.push_back(n - x - 1);
    }
    // debug(s);
    sol.push_back(s);
    go(s);
    // debug(a);
  }

  cout << sz(sol) << endl;
  for(int i = 0; i < sz(sol); i++) {
    cout << sz(sol[i]);
    for(int j : sol[i]) {
      cout << " " << j;
    }
    cout << endl;
  }
  return 0;
}
