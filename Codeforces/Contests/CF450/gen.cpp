#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) begin(x), end(x)



int main()
{
  int n = 1e5;
  int m = 1e5 - 1;
  int k = 1e5 - 1;
  cout << n << " " << m << " " << k << endl;
  for(int i = 0 ; i < m ; i++)
    cout << i + 1 << " " << i + 2 << " 1\n";
  for(int i = 0 ; i < k ; i++)
    cout << i + 1 << " 1\n";
  return 0;
}
