#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

int main()
{
  int n;
  cin >> n;
  if(n & 1){
    cout << 0 << endl;
  }else{
    n /= 2;
    cout << (1LL << n) << endl;
  }
  return 0;
}
