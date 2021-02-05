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
public:
  vector<T> fen;
  int n;
  fenwick(int _n) : n(_n) {
    fen.resize(n, T());
  }
  void add(int x, T v) {
    while(x < n) {
      fen[x] += v;
      x |= x + 1;
    }
  }
  T get(int x) {
    T v{};
    while(x >= 0) {
      v += fen[x];
      x = (x & (x + 1)) - 1;
    }
    return v;
  }
};


int n;
int arr[N];
int lis[N];

void calc_lis() {
  vector<int> tmp;
  for(int i = 0; i < n; i++) {
    int idx = lower_bound(all(tmp), arr[i]) - begin(tmp);
    if(idx >= sz(tmp)) {
      tmp.push_back(arr[i]);
    } else {
      tmp[idx] = arr[i];
    }
    lis[i] = idx + 1;
  }
}

ll inversion() {
  fenwick<int> bit(n);
  ll ans = 0;
  for(int i = n - 1; i >= 0; i--) {
    int x = arr[i] - 1;
    ans += bit.get(x);
    bit.add(x, 1);
  }
  return ans;
}

int cycles() {
  int ans = 0;
  vector<int> vis(n, 0);
  for(int i = 0; i < n; i++) {
    if(!vis[i]) {
      int len = 0;
      for(int cur = i; !vis[cur]; cur = arr[cur] - 1) {
        vis[cur] = 1;
        len++;
      }
      ans += len - 1;
    }
  }
  return ans;
}

int calc() {
  int j = n;
  for(int i = n - 1; i >= 0; i--) {
    if(arr[i] == j) {
      j--;
    }
  }
  return j;
}

int maxLis() {
  return n - *max_element(lis, lis + n);
}

int main()
{
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  calc_lis();

  cout << inversion() << " " << cycles() << " " << maxLis() << " " << calc() << endl;
  return 0;
}
