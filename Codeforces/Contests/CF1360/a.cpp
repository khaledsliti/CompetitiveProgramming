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
    int a, b;
    cin >> a >> b;
    int len = min(max(2 * a, b), min(max(2 * b, a), a + b));
    cout << len * len << endl;
  }
  return 0;
}
