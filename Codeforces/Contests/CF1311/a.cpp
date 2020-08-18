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
    int a, b;
    cin >> a >> b;
    if(a == b) cout << 0 << endl;
    else if(a < b){
      if((b - a) & 1) cout << 1 << endl;
      else cout << 2 << endl;
    }else{
      if((a - b) & 1) cout << 2 << endl;
      else cout << 1 << endl;
    }
  }  
  return 0;
}
