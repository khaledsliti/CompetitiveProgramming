// We only fail when we stop trying
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
namespace time_lib {
  std::chrono::system_clock::time_point start, last_time_cap;

  void init_time()
  {
    last_time_cap = start = std::chrono::high_resolution_clock::now();
  }

  void print_time(string name = "None")
  {
    chrono::system_clock::time_point now = std::chrono::high_resolution_clock::now();
    long long from_start = std::chrono::duration_cast<std::chrono::milliseconds>(now - start).count();
    long long from_last = std::chrono::duration_cast<std::chrono::milliseconds>(now - last_time_cap).count();
    cerr << name << " - from last = " << from_last << " ms, from start = " << from_start << " ms.\n";
    last_time_cap = now;
  }
}

const int L = 18;
const int N = 1 << L;
const int V = 100005;

int n, q;
int vi[N], wi[N];
vector<int> qu[N];

int main()
{
  time_lib::init_time();
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  // cin >> n;
  n = (1 << L) - 1;
  for(int i = 0; i < n; i++) {
    // cin >> vi[i] >> wi[i];
    vi[i] = 1, wi[i] = 1;
  }
  q = 1e5;
  // cin >> q;
  while(q--) {
    int v, L;
    // cin >> v >> L;
    v = n, L = 10;
    qu[--v].push_back(L);
  }
  for(int i = 0; i < n; i++) {
    int cur = i + 1;
    vector<int> val1, val2, we1, we2;
    int t = 0;
    while(cur > 0) {
      if(t) {
        val1.push_back(vi[cur - 1]);
        we1.push_back(wi[cur - 1]);
      } else {
        val2.push_back(vi[cur - 1]);
        we2.push_back(wi[cur - 1]);
      }
      cur >>= 1;
      t ^= 1;
    }
    vector<pair<ll, ll>> a, b;
    int m = sz(val1);
    for(int msk = 0; msk < (1 << m); msk++) {
      ll weight = 0, value = 0;
      for(int x = msk; x > 0; x -= x & -x) {
        int i = ffs(x);
        weight += we1[i];
        value += val1[i];
      }
      a.push_back({weight, value});
    }
    m = sz(val2);
    for(int msk = 0; msk < (1 << m); msk++) {
      ll weight = 0, value = 0;
      for(int x = msk; x > 0; x -= x & -x) {
        int i = ffs(x);
        weight += we2[i];
        value += val2[i];
      }
      b.push_back({weight, value});
    }
  }
  time_lib::print_time();
  return 0;
}
