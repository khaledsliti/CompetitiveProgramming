// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 1e5 + 5;

int n, k;

int main()
{
  int t;
  cin >> t;
  while(t--) {
    cin >> n >> k; k--;
    for(int i = n - 2, cnt = 1; i >= 0 ; i--, cnt++) {
      if(k >= cnt) {
        k -= cnt;
      } else {
        for(int j = n - 1 ; j > i ; j--) {
          if(k == 0){
            for(int l = 0 ; l < n ; l++){
              if(l == i || l == j) cout << 'b';
              else cout << 'a';
            }
            cout << endl;
            break;
          }
          k--;
        }
        break;
      }
    }
  }
  return 0;
}
