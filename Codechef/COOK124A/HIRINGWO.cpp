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

int k, x;
int cur[100];

int solve(vector<int>& p, int idx) {
  if(idx >= sz(p)) {
    int v[k];
    for(int i = 0; i < k; i++) {
      v[i] = 1;
    }
    for(int i = 0; i < sz(p); i++) {
      v[cur[i]] *= p[i];
    }
    int r = 0;
    for(int i = 0; i < k; i++) {
      if(v[i] == 1) return 1e9;
      r += v[i];
    }
    return r;
  }
  int r = 1e9;
  for(int i = 0; i < k; i++) {
    cur[idx] = i;
    r = min(r, solve(p, idx + 1));
  }
  return r;
}

void solve() {
  cin >> k >> x;
  vector<int> p;
  for(int i = 2; i * i <= x; i++) {
    if(x % i == 0) {
      p.push_back(1);
      while(x % i == 0) {
        p.back() *= i;
        x /= i;
      }
    }
  }
  if(x > 1) {
    p.push_back(x);
  }
  if(sz(p) <= k) {
    while(sz(p) < k) p.push_back(1);
    int s = 0;
    for(int i = 0; i < sz(p); i++) {
      s += p[i];
    }
    cout << s << endl;
  } else {
    cout << solve(p, 0) << endl;
  }
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
