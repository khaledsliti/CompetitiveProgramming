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

struct Item {
  int length;
  string pref, suff;
  long long cnt;
};

int calc(const string& s) {
  int ans = 0;
  for(int i = 0; i + 3 < sz(s); i++) {
    if(s.substr(i, 4) == "haha")
      ans++;
  }
  return ans;
}

Item merge(Item a, Item b) {
  Item r;
  r.length = a.length + b.length;
  r.cnt = a.cnt + b.cnt + calc(a.suff + b.pref);
  if(a.pref.size() == 3) {
    r.pref = a.pref;
  } else {
    r.pref = a.pref + b.pref;
    r.pref = r.pref.substr(0, 3);
  }
  if(b.suff.size() == 3) {
    r.suff = b.suff;
  } else {
    r.suff = a.suff + b.suff;
    r.suff = r.suff.substr(max(0, sz(r.suff) - 3), 3);
  }
  return r;
}

void solve() {
  int n;
  cin >> n;
  map<string, Item> var;
  long long lastValue;
  for(int i = 0; i < n; i++) {
    string x; cin >> x;
    string op; cin >> op;
    if(op == "=") {
      string a, b; cin >> a >> b >> b;
      var[x] = merge(var[a], var[b]);
    } else {
      string a; cin >> a;
      var[x] = {sz(a), a.substr(0, 3), a.substr(max(0, sz(a) - 3), 3), calc(a)};
    }
    lastValue = var[x].cnt;
  }
  cout << lastValue << endl;
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
