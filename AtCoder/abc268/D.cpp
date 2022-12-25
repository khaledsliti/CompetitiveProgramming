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

const int N = 8;

int n;
string s[N];
unordered_set<string> ex;
string sol = "-1";
string cur = "";

void go(int mask) {
  if(sol != "-1" || sz(cur) > 10) {
    return;
  }
  if(mask == (1 << n) - 1) {
    if(sz(cur) >= 3 && ex.find(cur) == ex.end()) {
      sol = cur;
    }
    return;
  }
  string add = "";
  for(int d = 1; d <= 1; d++) {
    if(mask) add += "_";
    for(int i = 0; i < n; i++) {
      if(mask & (1 << i)) continue;
      cur += add + s[i];
      go(mask | (1 << i));
      cur.resize(sz(cur) - sz(add) - sz(s[i]));
    }
  }
}


int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int m;
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    cin >> s[i];
  }
  while(m--) {
    string t;
    cin >> t;
    ex.insert(t);
  }
  go(0);
  cout << sol << endl;
  return 0;
}
