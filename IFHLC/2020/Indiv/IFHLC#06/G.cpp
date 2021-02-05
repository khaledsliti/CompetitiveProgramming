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

bool endsWith(string s, string p) {
  if(sz(s) < sz(p)) return false;
  reverse(all(s));
  reverse(all(p));
  while(sz(s) > sz(p)) {
    s.pop_back();
  }
  return s == p;
}

int main()
{
  #ifndef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif

  int T;
  cin >> T;
  while(T--) {
    string s;
    cin >> s;
    bool done = false;
    for(string p : { "ch", "x", "s", "o" }) {
      if(endsWith(s, p)) {
        s += "es";
        done = true;
        break;
      }
    }
    if(!done) {
      if(endsWith(s, "f")) {
        s.pop_back();
        s += "ves";
        done = true;
      } else if(endsWith(s, "fe")) {
        s.pop_back(); s.pop_back();
        s += "ves";
        done = true;
      }
    }
    if(!done && endsWith(s, "y")) {
      s.pop_back();
      s += "ies";
      done = true;
    }
    if(!done) {
      s += "s";
    }
    cout << s << endl;
  }
  return 0;
}
