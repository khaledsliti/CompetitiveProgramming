// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

long long n, m;

int main()
{
  cin >> n >> m;
  if(n <= m) {
    cout << n << endl;
  } else {
    long long w = n - m;
    long long l = 1, r = 2e9, x = 1;
    while(l <= r) {
      long long mid = l + (r - l) / 2;
      if(mid * (mid + 1) / 2 >= w) {
        x = mid;
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
    cout << m + x << endl;
  }
  return 0;
}
