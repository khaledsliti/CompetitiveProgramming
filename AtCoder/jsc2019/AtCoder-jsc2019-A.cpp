#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

int main()
{
  int M, D;
  cin >> M >> D;
  int ans = 0;
  for(int m = 1 ; m <= M ; m++){
    for(int d = 1 ; d <= D ; d++){
      int i = d % 10;
      int j = d / 10;
      if(i * j == m && i >= 2 && j >= 2)
        ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
