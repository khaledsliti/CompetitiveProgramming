#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 105;

int n, k, tot;
int arr[N];

int main()
{
  int T;
  cin >> T;
  while(T--){
    cin >> n >> tot >> k;
    for(int i = 0 ; i < n ; i++){
      cin >> arr[i];
    }
    bool yes = true;
    for(int i = 0 ; i < n - 1 && yes; i++){
      int nxt = arr[i + 1];
      int cur = arr[i];
      int b = max(0, nxt - k);
      if(cur > b){
        tot += cur - b;
      }else{
        int need = b - cur;
        if(need > tot){
          yes = false;
        }else{
          tot -= need;
        }
      }
    }
    if(!yes) cout << "NO" << endl;
    else cout << "YES" << endl;
  }
  return 0;
}
