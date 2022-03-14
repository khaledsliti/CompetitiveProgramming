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

vector<int> PFactors(int d) {
  vector<int> p;
  for(int i = 2; i * i <= d; i++) {
    while(d % i == 0) {
      p.push_back(i);
      d /= i;
    }
  }
  if(d > 1) {
    p.push_back(d);
  }
  return p;
}

bool IsPrime(int x) {
  return x > 1 && PFactors(x).size() <= 1; 
}

void solve() {
  int x, d;
  cin >> x >> d;
  int cnt = 0;
  while(x % d == 0) {
    cnt++;
    x /= d;
  }
  if (cnt <= 1) {
    cout << "NO" << endl;
    return;
  }
  if (x > 1 && !IsPrime(x)) {
    cout << "YES" << endl;
    return;
  }
  if (IsPrime(d)) {
    cout << "NO" << endl;
    return;
  }
  if (cnt <= 2) {
    cout << "NO" << endl;
    return;
  }
  if (cnt > 3) {
    cout << "YES" << endl;
    return;
  }
  //
  auto p = PFactors(d);
  for(int pp: p) {
    if(x * pp % d != 0) {
      cout << "YES" <<endl;
      return;
    }
  }
  cout << "NO" << endl;
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
/*
1000 = 50 . 20
1000 = 10 . 10 . 10

128 = 4 . 4 . 4 * 2
128 = 4 . 4 . 8

4 4 4 4

x = d^k * r
d^(k-1) * d*r

d d d d d (a*b*r)
d d d (d*a) (d*b*r)

r = 2
d = 4
a = b = 2

a * b = d
b * r not div by d


512 = 4 * 4 * 4 * 4 * 2

4 * 4 * 4 * 8
4 * 4 * 4 * 4

2 * 2 * 9

2 * 18
6 * 6

*/