// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

long long u, v;

void no() {
  cout << -1 << endl;
  exit(0);
}

int main()
{
  cin >> u >> v;
  if(v < u) no();
  if(u == 0 && v == 0) {
    cout << 0 << endl;
    return 0;
  }
  if(u == v) {
    cout << 1 << endl;
    cout << v << endl;
    return 0;
  }
  long long w = v - u;
  if(w & 1) no();
  w >>= 1;
  if(u & w) {
    cout << 3 << endl;
    cout << u << " " << w << " " << w << endl;
  }else {
    cout << 2 << endl;
    cout << (u | w) << " " << w << endl;
  }
  return 0;
}
