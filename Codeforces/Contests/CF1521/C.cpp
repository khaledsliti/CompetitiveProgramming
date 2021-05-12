// Guess Who's Back
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

const int N = 1e4 + 5;

vector<int> values;

int n;
int ans[N];
int one_pos, two_pos;
bool solved;

int ask(int t, int i, int j, int x) {
  // if(t == 1) {
  //   return max(min(x, values[i]), min(x + 1, values[j]));
  // }
  // return min(max(x, values[i]), max(x + 1, values[j]));
  cout << "? " << t << " " << i + 1 << " " << j + 1 << " " << x << endl;
  cout.flush();
  int res; cin >> res;
  assert(res != -1);
  return res;
}

void run_one() {
  for(int i = 0; i < n; i++) {
    if(i == one_pos) {
      ans[i] = 1;
    } else {
      ans[i] = ask(1, one_pos, i, n - 1);
    }
  }
}

void run_two() {
  for(int i = 0; i < n; i++) {
    if(i == two_pos) {
      ans[i] = 2;
    } else {
      ans[i] = ask(1, two_pos, i, n - 1);
      if(ans[i] == 2) ans[i] = 1;
    }
  }
}

bool process(int i) {
  int j = i + 1;
  int r = ask(2, i, j, 1);
  if(r == 1) {
    one_pos = i;
    run_one();
    return true;
  }
  if(r == 2) {
    int k = i - 1 >= 0 ? i - 1 : j + 1;
    r = ask(2, j, k, 1);
    if(r == 1) {
      one_pos = j;
      run_one();
    } else if(r == 2) {
      r = ask(2, k, j, 1);
      if(r == 1) {
        one_pos = k;
        run_one();
      } else {
        two_pos = j;
        run_two();
      }
    } else {
      two_pos = i;
      run_two();
    }
    return true;
  }
  return false;
}

void assert_ans() {
  vector<int> v;
  for(int i = 0; i < n; i++) {
    v.push_back(ans[i]);
  }
  sort(all(v));
  for(int i = 1; i < n; i++) {
    if(v[i - 1] == v[i]) {
      for(int i = 0; i < sz(values); i++) {
        cout << values[i] << " ";
      }
      cout << endl;
      assert(false);
    }
  }
}

void print() {
  cout << "!";
  for(int i = 0; i < n; i++)
    cout << " " << ans[i];
  cout << endl;
  // assert_ans();
  cout.flush();
}

void solve() {
  cin >> n;
  // values.clear(); values.resize(n);
  // for(int i = 0; i < n; i++) {
  //   cin >> values[i];
  // }
  one_pos = -1;
  two_pos = -1;
  solved = false;
  for(int i = 0; i + 1 < n && !solved; i += 2) {
    solved = process(i);
  }
  if(!solved) {
    process(n - 2);
  }
  print();
}

int main()
{
  int T;
  cin >> T;
  while(T--) {
    solve();
  }
  return 0;
}
