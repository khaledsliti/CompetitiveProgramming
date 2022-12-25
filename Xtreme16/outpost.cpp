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

struct Ranges {
  set<pair<int, int>> rng;
  void Add(int pos) {
    pair<int, int> nw = {pos, pos};
    auto it = rng.lower_bound(nw);
    if (it != rng.end() && nw.second + 1 == it->first) {
      nw.second = it->second;
      rng.erase(*it);
    }
    rng.insert(nw);
    it = rng.find(nw);
    if (it != rng.begin()) {
      --it;
      if (it->second + 1 == nw.first) {
        rng.erase(nw);
        nw.first = it->first;
        rng.erase(*it);
        rng.insert(nw);
      }
    }
  }
  void Delete(int pos) {
    auto it = rng.lower_bound({pos + 1, -1});
    if (it == rng.begin()) {
      return;
    }
    --it;
    int left = it->first;
    int right = it->second;
    rng.erase(*it);
    if (left < pos) {
      rng.insert({left, pos - 1});
    }
    if (pos < right) {
      rng.insert({pos + 1, right});
    }
  }
  pair<int, int> At(int pos) {
    auto it = rng.lower_bound({pos + 1, -1});
    if (it == rng.begin()) {
      return {-1, -1};
    }
    --it;
    if (it->second < pos) {
      return {-1, -1};
    }
    return *it;
  }
};


int n, m, t;
vector<array<int, 3>> vals;
Ranges rngs[11];

int solve(int x, int y) {
  int ret = 0;
  auto maxi = [&](int v) {
    ret = max(ret, v);
  };
  // In top
  pair<int, int> cur = {-1, m};
  for(int i = x; i < n; i++) {
    auto tmp = rngs[i].At(y);
    if(tmp.first == -1) {
      break;
    }
    cur.first = max(cur.first, tmp.first);
    cur.second = min(cur.second, tmp.second);
    maxi((i - x + 1) * (cur.second - cur.first + 1));
  }
  // In bottom
  cur = {-1, m};
  for(int i = x; i >= 0; i--) {
    auto tmp = rngs[i].At(y);
    if(tmp.first == -1) {
      break;
    }
    cur.first = max(cur.first, tmp.first);
    cur.second = min(cur.second, tmp.second);
    maxi((x - i + 1) * (cur.second - cur.first + 1));
  }
  // In left
  cur = {y, m};
  for(int i = x; i >= 0; i--) {
    auto tmp = rngs[i].At(y);
    if(tmp.first == -1) {
      break;
    }
    cur.second = min(cur.second, tmp.second);

    auto nw = cur;
    for(int k = x; k < n; k++) {
      auto tmp = rngs[k].At(y);
      if(tmp.first == -1) {
        break;
      }
      nw.second = min(nw.second, tmp.second);
      maxi((k - i + 1) * (nw.second - nw.first + 1));
    }
  }
  // In right
  cur = {-1, y};
  for(int i = x; i >= 0; i--) {
    auto tmp = rngs[i].At(y);
    if(tmp.first == -1) {
      break;
    }
    cur.first = max(cur.first, tmp.first);

    auto nw = cur;
    for(int k = x; k < n; k++) {
      auto tmp = rngs[k].At(y);
      if(tmp.first == -1) {
        break;
      }
      nw.first = max(nw.first, tmp.first);
      maxi((k - i + 1) * (nw.second - nw.first + 1));
    }
  }
  return ret;
}

void print() {
  vector<vector<int>> g(n, vector<int>(m, 0));
  for(int i = 0; i < n; i++) {
    for(auto r : rngs[i].rng) {
      for(int j = r.first; j<= r.second; j++) {
        g[i][j] = 1;
      }
    }
  }
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      cout << g[i][j] << " ";
    }
    cout << endl;
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m >> t;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      int x; cin >> x;
      vals.push_back({x, i, j});
    }
  }

  sort(all(vals));
  int j = 0;
  int ans = 0;
  for(int i = 0; i < sz(vals);) {
    int k = i;
    while(k < sz(vals) && vals[k][0] == vals[i][0]) {
      int x = vals[k][1];
      int y = vals[k][2];
      rngs[x].Add(y);
      k++;
    }
    while(vals[i][0] - vals[j][0] > t) {
      int x = vals[j][1];
      int y = vals[j][2];
      rngs[x].Delete(y);
      j++;
    }

    while(i < k) {
      ans = max(ans, solve(vals[i][1], vals[i][2]));
      i++;
    }
  }
  cout << ans << endl;
  return 0;
}
