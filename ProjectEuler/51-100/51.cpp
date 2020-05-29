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

const int N = 1e8;

int n, l, k;

int to_int(string s) {
  int r = 0;
  for(int i = 0; i < sz(s); i++)
    r = r * 10 + s[i] - '0';
  return r;
}

bool isPrime(int x) {
  for(int i = 2; i * i <= x; i++)
    if(x % i == 0)
      return false;
  return true;
}

bool check(int n) {
  if(!isPrime(n)) return false;
  string s;
  for(int a = n; a > 0; a /= 10) {
    s += char('0' + a % 10);
  }
  reverse(all(s));
  vector<vector<int>> sol;
  for(int msk = 1; msk < (1 << sz(s)); msk++) {
    if(__builtin_popcount(msk) != k)
      continue;
    bool same = true;
    int cur = -1;
    for(int i = 0; i < sz(s); i++)
      if(msk & (1 << i)) {
        if(cur == -1) {
          cur = s[i] - '0';
        } else if(cur != s[i] - '0') {
          same = false;
        }
      }
    if(!same) continue;
    vector<int> v;
    for(int d = (msk & 1) ? 1 : 0; d < 10; d++) {
      string t = s;
      for(int i = 0; i < sz(s); i++)
        if(msk & (1 << i))
          t[i] = char('0' + d);
      int r = to_int(t);
      if(isPrime(r)) v.pb(r);
    }
    if(sz(v) >= l) {
      sol.push_back(v);
    }
  }
  if(sz(sol)) {
    sort(all(sol));
    for(int i = 0; i < l; i++)
      cout << sol[0][i] << " ";
    cout << endl;
    return true;
  }
  return false;
}

int main()
{ 
  cin >> n >> k >> l;
  int st = 1;
  while(n-- > 1) st *= 10;
  int en = st * 10;
  for(int i = st; i < en; i++) {
    if(check(i)) {
      break;
    }
  }
  return 0;
}
