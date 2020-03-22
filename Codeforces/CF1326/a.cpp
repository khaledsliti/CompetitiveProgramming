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
    int n;
    cin >> n;
    if(n == 1) cout << -1 << endl;
    else {
      cout << 2;
      for(int i = 1 ; i < n ; i++)
        cout << 3;
      cout << endl;
    }
  }
  return 0;
}
