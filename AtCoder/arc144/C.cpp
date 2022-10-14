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

int n, k;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> k;
  // for(int k = 1; k < n; k++) {
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
      a[i] = i;
    }
    bool done = false;
    do {
      bool ok = true;
      for(int i = 0; i < n; i++) {
        ok &= abs(a[i] - i) >= k;
      }
      if(ok) {
        cout << n << " " << k << endl;
        for(int i = 0; i < n; i++) {
          cout << a[i] << " ";
        }
        cout << endl;
        done = true;
        break;
      }
    } while(next_permutation(all(a)));
    if(!done) {
      cout << -1 << endl;
      // break;
    }
  // }

  set<int> av, seen;
  for(int i = k; i < n; i++) {
    av.insert(i);
  }

  vector<int> sol(n);
  int cur = k;
  for(int i = 0; i < n; i++) {
    debug(av);
    if(av.size() == 0) {
      cout << -1 << endl;
      return 0;
    }
    sol[i] = *av.begin();
    seen.insert(sol[i]);
    av.erase(sol[i]);

    av.erase(cur);
    cur++;
    if(cur - 2 * k >= 0 && seen.find(cur - 2 * k) == seen.end()) {
      av.insert(cur - 2 * k);
    }
  }

  for(int x: sol) {
    cout << x + 1 << " ";
  }
  cout << endl;

  return 0;
}


/*

0 1 2 3 4 5 6 7
0 1 2 3 4 5 6 7 -> 0
1 0 1 2 3 4 5 6 -> 1
2 1 0 1 2 3 4 5 -> 2
3 2 1 0 1 2 3 4 -> 3
4 3 2 1 0 1 2 3 -> 4
5 4 3 2 1 0 1 2 -> 5
6 5 4 3 2 1 0 1 -> 6
7 6 5 4 3 2 1 0 -> 7

2   0 1   4 5 6
0 1 2 3 4 5 6 7
0 1 2 3 4 5 6 7 -> 0
1 0 1 2 3 4 5 6 -> 1
2 1 0 1 2 3 4 5 -> 2
3 2 1 0 1 2 3 4 -> 3
4 3 2 1 0 1 2 3 -> 4
5 4 3 2 1 0 1 2 -> 5
6 5 4 3 2 1 0 1 -> 6
7 6 5 4 3 2 1 0 -> 7

*/
