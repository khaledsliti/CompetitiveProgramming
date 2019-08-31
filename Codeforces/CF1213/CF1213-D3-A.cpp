#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

int main()
{
  int n;
  cin >> n;
  int x = 0, y = 0;
  for(int i = 0 ; i < n ; i++){
    int a;
    cin >> a;
    if(a & 1) x++;
    else y++;
  }
  cout << min(x, y) << endl;
  return 0;
}
