// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
typedef long long ll;

int n;


int main()
{
  cin >> n;
  int mx = 0;
  int number = 0;
  for(int len = 1; len < 10; len++) {
    mx = mx * 10 + 9;
    if(mx > 2 * n - 1) break;
    number = 2 * n - 1;
  }
  if(number == 0) {
    cout << 1LL * n * (n - 1) / 2 << endl;
    return 0;
  }
  return 0;
}
