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

template <int Mod>
class Modular {
  int v;
 public:
  template <typename T>
  Modular(T v): v(v % Mod) {
    if (v < 0) v += Mod;
  }
  void fix() { if (v < 0) v += Mod; }
  Modular operator+ (const Modular& rhs) const {
    return Modular(v + rhs.v);
  }
  Modular operator- (const Modular& rhs) const {
    return Modular(v - rhs.v);
  }
  Modular operator* (const Modular& rhs) const {
    return Modular(1LL * v * rhs.v);
  }
  template <typename T>
  Modular operator^ (T p) const {
    Modular r(1), a(v);
    while(p > 0) {
      if (p & 1) r = r * a;
      a = a * a;
      p >>= 1;
    }
    return r;
  }
  Modular inv(const Modular& a) const {
    return a ^ (Mod - 2);
  }
  Modular operator/ (const Modular& rhs) const {
    return *this * inv(rhs);
  }
  friend ostream& operator<< (ostream& cout, const Modular& rhs) {
    cout << rhs.v;
    return cout;
  }
};

const int Mod = 1e9 + 7;
using intMod = Modular<Mod>;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;
  intMod divs(1);
  intMod nn(1);
  intMod sum(1);
  for(int i = 0; i < n; i++) {
    int x, t;
    cin >> x >> t;
    divs = divs * (t + 1);
    nn = nn * (intMod(x) ^ t);
    sum = sum * (((intMod(x) ^ (t + 1)) - 1) / (x - 1));
  }
  cout << divs << " " << sum << " " << (nn ^ (divs / 2)) << endl;
  
  return 0;
}
