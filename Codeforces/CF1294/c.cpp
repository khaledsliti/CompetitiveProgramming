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
  int T;
  cin >> T;
  while(T--){
    int n;
    cin >> n;
    bool found = false;
    for(int p = 2 ; p * p < n ; p++){
      if(n % p == 0){
        int d = n / p;
        for(int q = 2 ; q * q < d ; q++){
          if(d % q == 0 && q != p){
            int t = d / q;
            if(t != p && t != q){
              found = true;
              cout << "YES\n" << p << " " << q << " " << t << endl;
              break;
            }
          }
        }
        break;
      }
    }
    if(!found)
      cout << "NO" << endl;
  }
  return 0;
}
