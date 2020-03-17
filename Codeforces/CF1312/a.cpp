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
  int t;
  cin >> t;
  while(t--) {
    int n, m;
    cin >> n >> m;
    if(n % m == 0) cout << "YES" << endl;
    else cout << "No" << endl;
  }
  return 0;
}
