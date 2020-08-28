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
  while(t--){
    int n, m;
    cin >> n >> m;
    int sum = 0;
    for(int i = 0 ; i < n ; i++) {
      int a;
      cin >> a;
      sum += a;
    }
    cout << min(m, sum ) << endl;
  }
  return 0;
}
