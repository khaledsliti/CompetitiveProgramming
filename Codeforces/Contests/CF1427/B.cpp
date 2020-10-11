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

int n, k;
char s[N];

void solve() {
  scanf("%d%d", &n, &k);
  scanf("%s", s);
  int score = 0;
  int tot = 0;
  vector<int> pos;
  for(int i = 0; i < n; i++) {
    if(s[i] == 'W') {
      score++;
      tot++;
      pos.push_back(i);
      if(i > 0 && s[i - 1] == 'W') {
        score++;
      }
    }
  }
  if(score == 0) {
    k = min(k, n);
    cout << max(0, k * 2 - 1) << endl;
    return;
  }
  vector<int> v;
  for(int i = 1; i < sz(pos); i++) {
    if(pos[i] > pos[i - 1] + 1) {
      v.push_back(pos[i] - pos[i - 1] - 1);
    }
  }

  sort(rall(v));

  while(k > 0 && sz(v) > 0) {
    int s = v.back();
    v.pop_back();
    if(k >= s) {
      k -= s;
      score += s * 2 + 1;
      tot += s;
    } else {
      score += k * 2;
      tot += k;
      k = 0;
      break;
    }
  }

  while(k > 0 && tot < n) {
    k--;
    tot++;
    score += 2;
  }

  cout << score << endl;
}

int main()
{
  int T;
  scanf("%d", &T);
  while(T--) {
    solve();
  }
  return 0;
}
