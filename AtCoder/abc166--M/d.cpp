// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()



int main()
{
  int x;
  cin >> x;
  for(int a = -1000; a <= 1000 ; a++) {
    for(int b = -1000; b <= 1000; b++) {
      long long s = 1LL * a * a * a * a * a - 1LL * b * b * b * b * b;
      if(s == x) {
        cout << a << " " << b << endl;
        return 0;
      }
    }
  }
  return 0;
}
