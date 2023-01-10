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

const ll Mod = 4294967296LL;

ll get_hash(string s) {
  cout << s << endl;
  ll r = 0, a = 1;
  for (int i = sz(s) - 1; i >= 0; i--) {
    r += s[i] * a % Mod;
    r %= Mod;
    a = a * 31 % Mod;
  }
  return r;
}

int main() {
  cout << char(62) << endl;
  string s = "Coolh4cker0780578>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>";
  cout << get_hash(s) << endl;

  return 0;
  string p = s;

  p = p.back() + p;
  p.pop_back();

  cout << p << endl;
  cout << get_hash(p) << endl;
  return 0;
}
