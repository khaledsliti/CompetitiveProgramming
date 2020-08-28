#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

int a[3];

int main()
{
  int T;
  cin >> T;
  while(T--){
    for(int i = 0 ; i < 3 ; i++)
      cin >> a[i];
    sort(a, a + 3);
    int r = min(a[2] - a[1], a[0]);
    a[1] += r;
    a[0] -= r;
    if(a[0])
      a[1] += a[0] / 2;
    cout << a[1] << endl;
  }
  return 0;
}
