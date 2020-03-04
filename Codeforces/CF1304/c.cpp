#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 101;

int n;
int t[N], h[N], l[N];

int main()
{
  int T;
  cin >> T;
  while(T--){
    int lo, hi;
    cin >> n >> lo;
    hi = lo;
    int cur = 0;
    bool yes = true;
    for(int i = 0 ; i < n ; i++)
      cin >> t[i] >> l[i] >> h[i];
    for(int i = 0 ; i < n ; i++){
      hi += t[i] - cur;
      lo -= t[i] - cur;
      if(lo > h[i] || hi < l[i]){
        cout << "NO" << endl;
        yes = false;
        break;
      }
      hi = min(hi, h[i]);
      lo = max(lo, l[i]);
      cur = t[i];
    }
    if(yes)
      cout << "YES" << endl;
  }
  return 0;
}

//Check array sizes
//Check limits: N = 1 ? N = Max ? .. etc
//Check time complexity