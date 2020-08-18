#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

long long gcd(long long a, long long b)
{
  if(!b)
    return a;
  return gcd(b, a % b);
}

long long n, m;
long long a, b;

int main()
{
  int q;
  cin >> n >> m >> q;
  long long g = gcd(n, m);
  // cout << n / g << " " << m / g << endl;
  while(q--){
    long long t1, a1, t2, a2;
    cin >> t1 >> a1 >> t2 >> a2;
    long long x = t1 == 1 ? (a1 - 1) / (n / g) : (a1 - 1) / (m / g);
    long long y = t2 == 1 ? (a2 - 1) / (n / g) : (a2 - 1) / (m / g);
    cout << (x == y ? "YES" : "NO") << endl;
  }
  return 0;
}
