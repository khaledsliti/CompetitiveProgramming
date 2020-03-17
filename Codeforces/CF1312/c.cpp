// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 35;

int n, k;
int occ[70];

int main()
{
  int t;
  cin >> t;
  while(t--) {
    cin >> n >> k;
    memset(occ, 0, sizeof occ);
    for(int i = 0 ; i < n ; i++) {
      long long cur;
      cin >> cur;
      int p = 1;
      while(cur > 0) {
        occ[p] += cur % k;
        cur /= k;
        p++;
      }
    }
    bool bad = false;
    for(int i = 0 ; i < 70 ; i++)
      if(occ[i] > 1)
        bad = true;
    if(bad){
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
    }
  }
  return 0;
}
