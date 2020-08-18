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

int main()
{
  int T;
  cin >> T;
  while(T--) {
    int n, m;
    cin >> n >> m;
    if(n == 1) cout << 0 << endl;
    else if(n == 2) cout << m << endl;
    else cout << 2 * m << endl;
  }
  return 0;
}
