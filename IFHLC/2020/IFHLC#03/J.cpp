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

const int N = 131;

int a;
ll b, ans;
int isp[N];
vector<int> pr;

void go(int idx, ll prod, int cnt) {
  if(prod > b) return;
  if(idx >= sz(pr)) {
    if(cnt == 0) return;
    ans += (cnt & 1 ? 1 : -1) * (b / prod);
    return;
  }
  go(idx + 1, prod * pr[idx], cnt + 1);
  go(idx + 1, prod, cnt);
}

void solve() {
  cin >> a >> b;
  pr.clear();
  for(int cur = 2; cur <= a; cur++) {
    if(isp[cur]) {
      pr.push_back(cur);
    }
  }
  reverse(all(pr));
  ans = 0;
  go(0, 1, 0);
  cout << ans << endl;
}

int main()
{
  for(int i = 2; i < N; i++)
    isp[i] = 1;
  for(int i = 2; i < N; i++) {
    if(isp[i]) {
      for(int j = i * 2; j < N; j += i) {
        isp[j] = 0;
      }
    }
  }
  int T;
  cin >> T;
  while(T--) {
    solve();
  }
  return 0;
}