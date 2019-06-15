#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

int main()
{
  int n, k;
  while(cin >> n >> k){
    if(k == 1) cout << 0 << endl;
    else cout << (n - k) << endl;
  }
  return 0;
}
