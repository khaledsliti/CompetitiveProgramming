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

int n, e, d;
vector<pair<int, int>> cards;
vector<pair<int, int>> player;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> e >> d;
  for(int i = 0; i < n; i++) {
    player.push_back(mp(i, 0));
  }
  while(e--) {
    int x;
    cin >> x;
    cards.push_back({x, -1});
  }
  while(d--) {
    int x;
    cin >> x;
    cards.push_back({x, 1});
  }

  sort(all(cards));
  int idx = 0, last = 0;
  for(int i = 0; i < sz(cards); i++) {
    if(sz(player) == 1) break;
    int steps = cards[i].first - last;
    idx = (idx + steps) % sz(player);

    // debug(idx);

    if(cards[i].second == 1) {
      player[idx].second = min(player[idx].second + 1, 5);
      idx = (idx + 1) % sz(player);
    } else {
      if(player[idx].second == 0) {
        player.erase(player.begin() + idx);
        idx %= sz(player);
      } else {
        player[idx].second--;
        idx = (idx + 1) % sz(player);
      }
    }

    // for(int i = 0; i < sz(player); i++) {
    //   cout << player[i].first << " " << player[i].second << endl;
    // }
    // cout << endl;

    last = cards[i].first + 1;
  }

  if(sz(player) == 1) cout << player.back().first << endl;
  else cout << -1 << endl;
  return 0;
}
