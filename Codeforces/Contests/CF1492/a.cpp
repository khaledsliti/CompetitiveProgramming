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

long long solve(long long p, long long a) {
  long long i = p;
  p = p / a * a;
  if(p < i) p += a;
  return p - i;
}

int main()
{
  int T;
  cin >> T;
  while(T--) {
    long long a, b, c, p;
    cin >> p >> a >> b >> c;
    cout << min(min(solve(p, a), solve(p, b)), solve(p, c)) << endl;
  }
  return 0;
}
