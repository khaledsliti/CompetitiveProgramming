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
    int x, y, a, b;
    cin >> x >> y >> a >> b;
    int s = a + b;
    int d = y - x;
    if(d % s == 0){
      cout << d / s << endl;
    }else{
      cout << -1 << endl;
    }
  }
  return 0;
}

//Check array sizes
//Check limits: N = 1 ? N = Max ? .. etc
//Check time complexity