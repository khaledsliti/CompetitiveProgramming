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

const long long LIMIT = 1e17;

set<long long> numbers;

void gen() {
  for(int s = 0; s <= 9; s++) {
    for(int delta = -9; delta <= 9; delta++) {
      int d = s;
      long long n = d;
      while(true) {
        numbers.insert(n);
        if(n > LIMIT) break;
        d = d + delta;
        if(d < 0 || d > 9) break;
        if(n * 10 + d == n) break;
        n = n * 10 + d;
      }
    }
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  gen();
  // for(long long x: numbers) {
  //   cout << x << endl;
  // }

  long long x; cin >> x;
  cout << *numbers.lower_bound(x) << endl;
  return 0;
}
