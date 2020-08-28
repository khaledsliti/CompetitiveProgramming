#include <bits/stdc++.h>
using namespace std;
 
int main()
{
  int x;
  cin >> x;
  x %= 4;
  if(x == 0) cout << "1 A" << endl;
  else if(x == 1) cout << "0 A" << endl;
  else if(x == 2) cout << "1 B" << endl;
  else if(x == 3) cout << "2 A" << endl;
  return 0;
}
