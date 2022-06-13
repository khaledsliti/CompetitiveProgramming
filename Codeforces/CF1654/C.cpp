// RedStone
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;

const int N = 2e5 + 5;

int n;
long long a[N];
map<long long, long long> fr;
bool ok;

void add(map<long long, long long> ws, long long v) {
  if(!sz(ws)) return;
  for(auto x: ws) {
    fr[x.first] += v * x.second;
    if(fr[x.first] < 0) {
      ok = false;
    }
  }
  map<long long, long long> nxt;
  for(auto x: ws) {
    if (x.first != 1) { 
      long long a = x.first, cnt = x.second;
      nxt[a / 2] += cnt;
      nxt[a - a / 2] += cnt;
    }
  }
  add(nxt, v);
}

void solve() {
  cin >> n;
  long long w = 0;
  fr.clear();
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    w += a[i];
  }
  ok = true;
  map<long long, long long> tmp;
  tmp.insert({w, 1});
  add(tmp, 1);
  sort(a, a + n);
  reverse(a, a + n);
  for(int i = 0; i < n; i++) {
    ok = true;
    map<long long, long long> tmp;
    tmp.insert({a[i], 1});
    add(tmp, -1);
    if(!ok) {
      cout << "NO" << endl;
      return;
    }
  }
  cout << "YES" << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int T; cin >> T;
  while(T--) {
    solve();
  }
  return 0;
}
