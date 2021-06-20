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

const int N = 2e5 + 5;

struct Node {
  int prefMax, suffMax, prefMin, suffMin, sum;
  Node() {
    prefMax = suffMax = prefMin = suffMin = sum = 0;
  }
  Node(int x) {
    prefMax = suffMax = prefMin = suffMin = sum = x;
  }
};

int n;
pair<int, int> arr[N];
Node st[N << 2];
int ans[N];

Node merge(const Node& a, const Node& b) {
  Node r(0);
  r.prefMax = max(a.prefMax, a.sum + b.prefMax);
  r.prefMin = min(a.prefMin, a.sum + b.prefMin);
  r.sum = a.sum + b.sum;
  r.suffMax = max(a.suffMax + b.sum, b.suffMax);
  r.suffMin = min(a.suffMin + b.sum, b.suffMin);
  return r;
}

void build(int cur, int s, int e) {
  if(s == e) {
    st[cur] = Node(1);
    return;
  }
  int l = 2 * cur + 1;
  int r = 2 * cur + 2;
  int mid = (s + e) / 2;
  build(l, s, mid);
  build(r, mid + 1, e);
  st[cur] = merge(st[l], st[r]);
}

void update(int cur, int s, int e, int idx, int newVal) {
  if(s > idx || e < idx) return;
  if(s == e) {
    st[cur] = Node(newVal);
    return;
  }
  int l = 2 * cur + 1;
  int r = 2 * cur + 2;
  int mid = (s + e) / 2;
  update(l, s, mid, idx, newVal);
  update(r, mid + 1, e, idx, newVal);
  st[cur] = merge(st[l], st[r]);
}

Node get(int cur, int s, int e, int i, int j) {
  if(s > j || e < i || i > j) return Node(0);
  if(s >= i && e <= j) return st[cur];
  int l = 2 * cur + 1;
  int r = 2 * cur + 2;
  int mid = (s + e) / 2;
  Node left = get(l, s, mid, i, j);
  Node right = get(r, mid + 1, e, i, j);
  return merge(left, right);
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> arr[i].first;
    arr[i].second = i;
  }
  sort(arr, arr + n);
  reverse(arr, arr + n);
  
  build(0, 0, n - 1);

  for(int i = 0; i < n; i++) {
    vector<int> pos;
    int j = i;
    while(arr[i].first == arr[j].first) {
      pos.push_back(arr[j].second);
      j++;
    }
    // max
    for(int cur: pos) {
      Node left = get(0, 0, n - 1, cur, n - 1);
      Node right = get(0, 0, n - 1, 0, cur - 1);
      int curAns = left.prefMax + max(0, right.suffMax);
      if(curAns > 0) {
        ans[cur] = max(ans[cur], (curAns + 1) / 2 - 1);
      }
    }

    // update
    for(int i: pos) {
      update(0, 0, n - 1, i, -1);
    }
    
    // min
    for(int cur: pos) {
      Node left = get(0, 0, n - 1, cur, n - 1);
      Node right = get(0, 0, n - 1, 0, cur - 1);
      int curAns = left.prefMin + min(0, right.suffMin);
      if(curAns < 0) {
        ans[cur] = max(ans[cur], -curAns / 2);
      }
    }
    
    i = j - 1;
  }



  for(int i = 0; i < n; i++)
    cout << ans[i] << " ";
  cout << endl;

  return 0;
}
