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

const int N = 2e5 + 5;

template<typename T>
class fenwick {
  vector<T> fen;
  int n;
  void addPr(int x, T v) {
    for(int i = x; i < n; i += i & -i) {
      fen[i] += v;
    }
  }
  T getPr(int x) {
    T v{};
    for(int i = x; i > 0; i -= i & -i) {
      v += fen[i];
    }
    return v;
  }
public:
  fenwick(int _n) : n(_n + 1) {
    fen.resize(n, T());
  }
  void add(int x, T v) {
    addPr(x + 1, v);
  }
  T get(int x) {
    return getPr(x + 1);
  }
  T get(int l, int r) {
    return get(r) - get(l - 1);
  }
};

struct Seg {
  int l, r;
  int idx;
};

int n;
Seg arr[N];
int in[N], out[N];

void reduce() {
  map<int, int> id;
  for(int i = 0; i < n; i++) {
    id[arr[i].l];
    id[arr[i].r];
  }
  int cur_id = 0;
  for(auto& i : id) {
    i.second = cur_id++;
  }
  for(int i = 0; i < n; i++) {
    arr[i].l = id[arr[i].l];
    arr[i].r = id[arr[i].r];
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> arr[i].l >> arr[i].r;
    arr[i].idx = i;
  }

  reduce();

  sort(arr, arr + n, [&](const Seg& a, const Seg& b) {
    if(a.r != b.r) return a.r < b.r;
    return a.l > b.l;
  });

  fenwick<int> fn(3 * N);
  for(int i = 0; i < n; i++) {
    in[arr[i].idx] = fn.get(arr[i].l, arr[i].r);
    fn.add(arr[i].l, 1);
  }

  for(int i = 0; i < n; i++) {
    fn.add(arr[i].l, -1);
  }

  sort(arr, arr + n, [&](const Seg& a, const Seg& b) {
    if(a.r != b.r) return a.r > b.r;
    return a.l < b.l;
  });

  for(int i = 0; i < n; i++) {
    out[arr[i].idx] = fn.get(0, arr[i].l);
    fn.add(arr[i].l, 1);
  }

  for(int i = 0; i < n; i++) {
    cout << in[i] << " ";
  }
  cout << endl;
  for(int i = 0; i < n ;i++) {
    cout << out[i] << " ";
  }
  cout << endl;
  
  return 0;
}
